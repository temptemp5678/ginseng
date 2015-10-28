<?php
/**
 * @file
 */

/**
 * class
   $UserQuery = new UserQuery();
   $UserQuery->allUserUid();
 *
 */
class UserQuery {
  /**
   * @parameter ,
   *
   * @return array,
   * all Meeting NID
   */
  public function allUserUid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'user')
      ->propertyCondition('status', 1);

    $result = $query->execute();

    $uid_array = NULL;
    if (isset($result['user'])) {
      if (count($result['user']) > 0 ) {
        $uid_array = array_keys($result['user']);
      }
    }

    return $uid_array;
  }

}
