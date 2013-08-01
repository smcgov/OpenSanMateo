<?php
/**
 * @file
 * custom-pager.tpl.php
 *
 * Theme implementation to display a custom pager.
 *
 * Default variables:
 * - $previous: A formatted <A> link to the previous item.
 * - $next: A formatted <A> link to the next item.
 * - $key: Formatted text describing the item's position in the list.
 * - $position: A textual flag indicating how the pager is being displayed.
 *   Possible values include: 'top', 'bottom', and 'block'.
 *
 * Other variables:
 * - $nav_array: An array containing the raw node IDs and position data of the
 *   current item in the list.
 * - $node: The current node object.
 * - $pager: The pager object itself.
 *
 * @see custom_pagers_preprocess_custom_pager()
 */
?>
<ul class="custom-pager custom-pager-<?php print $position; ?>">
<li class="previous"><?php print $previous; ?></li>
<li class="key"><?php print $key; ?></li>
<li class="next"><?php print $next; ?></li>
</ul>
