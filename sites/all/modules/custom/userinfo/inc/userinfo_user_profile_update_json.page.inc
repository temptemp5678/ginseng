<?php

/**
 * Implements page_callback(), callback from hook_menu()
 * embed a dash table to show table
 */
function _userinfo_user_profile_update_json($uid = NULL) {
  /**
   * Validate the request is a post and return proper response code on failure.
   */
  // if ($_SERVER['REQUEST_METHOD'] != 'POST'){
  //   header('HTTP/1.1 405 Not Post');
  // }
  /**
   * Authenticate the user, or key and return proper response code on failure.
   */
  // elseif ($_SERVER['PHP_AUTH_USER'] != 'trusted user') {
  //   header('HTTP/1.1 401 Not Authorized');
  // }

  /**
   * When data type and field validation fails return a 204.
   * validating on a key to validate the user permission
   */
  // elseif ($validation == FALSE) {
  //   header('HTTP/1.1 204 Incorrect Data');
  // }

  /** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * to obtain stream inputs by using file_get_contents
   */
  $received_json = file_get_contents("php://input",  TRUE);
  $json_fields = drupal_json_decode($received_json, TRUE);

  /** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  $UserAction = new UserAction($uid);
  $UserAction->updateUser($uid, $json_fields);

  $output = 'Update User Profile';

  watchdog('userinfo', 'Update User Profile by JSON');

  return $output;

  /**
   * After completing the payload a notice of success to inform the application it’s POST was a success.
   * Set header to indicate the item was saved.
   */
  // header('HTTP/1.1 201 Created');
}

