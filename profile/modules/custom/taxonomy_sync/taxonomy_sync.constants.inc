<?php
/**
 * @file
 *
 * Module constants
 */

// Config variables from admin form
define('TAXONOMY_SYNC_MASTER', 'taxonomy_sync_master');
define('TAXONOMY_SYNC_MASTER_URL', 'taxonomy_sync_master_url');
define('TAXONOMY_SYNC_VOCAB', 'taxonomy_sync_vocab');

// Callback URL for master site - used by master and client code
define('TAXONOMY_SYNC_CALLBACK_URL', 'gta-terms-sync/list');

// Constant for watchdog msg tagging
define('TAXONOMY_SYNC_WATCHDOG', 'taxonomy_sync');

// Table name and cols used in schema and DB ops
define('TAXONOMY_SYNC_TABLE', 'taxonomy_sync');
define('TAXONOMY_SYNC_COL_MASTER_TID', 'master_tid');
define('TAXONOMY_SYNC_COL_LOCAL_VID', 'local_vid');
define('TAXONOMY_SYNC_COL_LOCAL_TID', 'local_tid');
define('TAXONOMY_SYNC_COL_LAST_UPDATE_HASH', 'last_update_hash');

// Stats categories; see _taxonomy_sync_stats
define('TAXONOMY_SYNC_UPDATE', 'update');
define('TAXONOMY_SYNC_INSERT', 'insert');
define('TAXONOMY_SYNC_DELETE', 'delete');
define('TAXONOMY_SYNC_UNCHANGED', 'unchanged');

// Stats operations
define('TAXONOMY_SYNC_STATS', '_taxonomy_sync_stats');
