<?php

/*******************************************************************************
 * DRUSH SUPPORT
 ******************************************************************************/

function elysia_cron_drush_detect() {
  return (!isset($_SERVER['SERVER_SOFTWARE']) && (php_sapi_name() == 'cli' || (is_numeric($_SERVER['argc']) && $_SERVER['argc'] > 0))) && function_exists('drush_main');
}

function elysia_cron_drush_die() {
  if (function_exists('drush_bootstrap_finish')) {
    // Only in Drush5
    drush_bootstrap_finish();
    drush_die();
  } else {
    // Drush4
    drush_set_context("DRUSH_EXECUTION_COMPLETED", TRUE);
    exit();
  }
}

function elysia_cron_drush_invoke($replace_core_cron = false) {
  $args = drush_get_arguments();
  array_shift($args);
  
  // If invoked like "core-cron" i do the same as that: execute "run"
  if ($replace_core_cron && empty($args)) {
    $args = array("run");
  }
  
  call_user_func_array('drush_elysia_cron_run_wrapper', $args);
  elysia_cron_drush_die();
}

/**
 * Implementation of hook_drush_command().
 */
function elysia_cron_drush_command() {
  $items = array();

  $items['elysia-cron'] = array(
    'description' => "Run all cron tasks in all active modules for specified site using elysia cron system. This replaces the standard \"core-cron\" drush handler.", // TODO dt
    'callback'    => 'drush_elysia_cron_run_wrapper',
    'arguments' => array(
      'op' => 'Operation: list, run, disable, enable',
      'target' => 'Target of operation (optional): usually a task name or a channel name starting with "@"',
    ),
    'examples' => array(
      'elysia-cron run' => 'Run all cron tasks in all active modules (as the standard "core-cron")',
      'elysia-cron run --verbose' => 'Run all cron tasks in verbose mode',
      'elysia-cron run @channel' => 'Run all cron tasks in specified channel',
      'elysia-cron run search_cron --ignore-time' => 'Run only search index build task (force execution)',
      'elysia-cron list --elysia-cron-verbose' => 'List all channels/tasks in verbose mode',
      'elysia-cron disable search_cron' => 'Disable search index build task',
    ),
    'options' => array(
      'quiet' => 'suppress all output',
      'verbose' => 'enable extended output',
      'elysia-cron-verbose' => 'enable extended output (the same as --verbose, but without enabling drush verbose mode)',
      'ignore-disable' => 'run channels/tasks even if disabled',
      'ignore-time' => 'run channels/tasks even if not ready for execution',
      'ignore-running' => 'run channels/tasks even if already running',
    ),
  );

  return $items;
}

/**
 * A drush command callback.
 *
 * wraps the elysia_cron_run function, passing manual = true
 */
function drush_elysia_cron_run_wrapper($op = false, $target = false) {
  /*
    drush_log("test notice", "notice");
    drush_log("test ok", "ok");
    drush_log("test completed", "completed");
    drush_log("test warning", "warning");
    drush_log("test error", "error");
    drush_print("print");
  */
  global $elysia_cron_drush;
  
  $quiet = drush_get_option("quiet", false);
  $verbose = drush_get_option("verbose", false);
  if (!$verbose) {
    $verbose = drush_get_option("elysia-cron-verbose", false);
  }
  $elysia_cron_drush = $quiet ? 1 : !$verbose ? 2 : 3; 
  
  switch ($op) {
    case 'list':
      global $elysia_cron_settings_by_channel;
      elysia_cron_initialize();
      foreach ($elysia_cron_settings_by_channel as $channel => $jobs) {
        if (!$verbose) {
          $line = array("@" . $channel);
        } else {
          $line = array("Channel: @" . $channel);
          if ($running = elysia_cron_is_channel_running($channel)) {
            $line[] = "RUNNING NOW, since " . elysia_cron_date($running);
          }
          if (!empty($jobs['#data']['disabled'])) {
            $line[] = "DISABLED";
          }
          if (!$running) {
            $line[] = "Last run: " . elysia_cron_date(_ec_variable_get('elysia_cron_last_run', 0));
          }
        }
        drush_print(implode($line, ", "));
        foreach ($jobs as $job => $conf) if ($job{0} != '#') {
          if (!$verbose) {
            $line = array($job);
          } else {
            $line = array("- Job: " . $job);
            if (!empty($conf['running'])) {
              $line[] = "RUNNING NOW, since " . elysia_cron_date($conf['running']);
            }
            if (!empty($conf['disabled'])) {
              $line[] = "DISABLED";
            }
            if (empty($conf['running']) && elysia_cron_should_run($conf)) {
              $line[] = "Ready to run";
            }
            if (empty($conf['running'])) {
              $line[] = "Last run: " . elysia_cron_date($conf['last_run']);
            }
          }
          drush_print(implode($line, ", "));
        }
      }
      break;

    case 'run':
      if (empty($target)) {
        elysia_cron_run(true, drush_get_option("ignore-disable", false), drush_get_option("ignore-time", false), drush_get_option("ignore-running", false));
        //drush_log("Cron run complete", "completed");
      }
      elseif ($target{0} == '@') {
        elysia_cron_initialize();
        if (elysia_cron_channel_exists(substr($target, 1))) {
          elysia_cron_run_channel(substr($target, 1), drush_get_option("ignore-disable", false), drush_get_option("ignore-time", false), drush_get_option("ignore-running", false));
          //drush_log("Cron run complete", "completed");
        } else {
          drush_set_error('Channel ' . substr($target, 1) . ' does not exists');
        }
      }
      else {
        elysia_cron_initialize();
        if (elysia_cron_job_exists($target)) {
          elysia_cron_run_job($target, drush_get_option("ignore-disable", false), drush_get_option("ignore-time", false), drush_get_option("ignore-running", false));
          //drush_log("Cron run complete", "completed");
        } else {
          drush_set_error('Job ' . $target . ' does not exists');
        }
      }
      break;

    case 'disable':
    case 'enable':
      if (!empty($target)) {
        if ($target{0} == '@') {
          elysia_cron_set_channel_disabled(substr($target, 1), $op == 'disable');
        } else {
          elysia_cron_set_job_disabled($target, $op == 'disable');
        }
        drush_log("Done", "ok");
      } else {
        drush_set_error('Target not specified');
      }
      
      break;

      break;
      
    default:
      drush_print_help(drush_get_command());
  }
}
