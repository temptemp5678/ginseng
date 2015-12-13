<?php
/**
 * callback from hook_menu()
 */
function _jsoninfo_node_all_ginseng_data() {
  $SourceJson = new SourceJson();
  drupal_json_output($SourceJson->allGinsengData());
}

