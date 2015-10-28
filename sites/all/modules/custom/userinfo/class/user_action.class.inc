<?php
/**
 * @file
 */

/**
 * class
 * $UserAction = new UserAction($para);
 */
class UserAction {

  /** - - - - - - action - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @parameter is nid or node object
   *  node_save()
   */
  public function updateUser($uid = NULL, $fields = array()) {

    if (is_numeric($uid)) {
      $user = user_load($uid);
    }

    /** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    if (is_array($fields)) {

      $edit = array();

      foreach ($fields as $field_name => $value) {
        if ($field_name == 'profile_obj_email') {
          $edit['mail'] = $value;
          continue;
        }
        if ($field_name == 'profile_obj_password') {
          $edit['pass'] = $value;
          continue;
        }
        if ($field_name == 'profile_obj_timezone') {
          $edit['timezone'] = $value;
          continue;
        }

        // custom fields
        $field_info = field_info_field($field_name);
        if ($field_info) {
          $field_type = $field_info['type'];

          switch ($field_type) {
            case 'datestamp':
            case 'list_integer':
            case 'number_integer':
            case 'text':
            case 'text_long':
              $edit[$field_name]['und'][0]['value'] = $value;
              break;
            case 'entityreference':
              if ($value) {
                $edit[$field_name]['und'][0]['target_id'] = $value;
              }
              break;

            default:
              break;
          }
        }
      }
    }

    user_save($user, $edit);
  }
}
