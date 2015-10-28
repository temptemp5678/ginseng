<?php
/**
 * @file
 */

/**
 * class
   $NodeQuery = new NodeQuery();
   $NodeQuery->allNotifylogNid();
 *
 */
class NodeQuery {
  /**
   * @parameter ,
   *
   * @return array,
   * all Meeting NID
   */
  public function allMeetingNid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'meeting')
      ->propertyCondition('status', NODE_PUBLISHED);

    $result = $query->execute();

    $nid_array = NULL;
    if (isset($result['node'])) {
      if (count($result['node']) > 0 ) {
        $nid_array = array_keys($result['node']);
      }
    }

    return $nid_array;
  }

  /**
   * @parameter array,
   *
   * @return array,
   * all Notify log NID
   */
  public function allNotifylogNid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'notify_log')
      ->propertyCondition('status', NODE_PUBLISHED);

    $result = $query->execute();

    $nid_array = NULL;
    if (isset($result['node'])) {
      if (count($result['node']) > 0 ) {
        $nid_array = array_keys($result['node']);
      }
    }

    return $nid_array;
  }

  /**
   * @parameter array,
   *
   * @return array,
   * all Notify log NID
   */
  public function allSupportNid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'faq')
      ->propertyCondition('status', NODE_PUBLISHED);

    $result = $query->execute();

    $nid_array = NULL;
    if (isset($result['node'])) {
      if (count($result['node']) > 0 ) {
        $nid_array = array_keys($result['node']);
      }
    }

    return $nid_array;
  }


  /** - - - - - - with condition - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @parameter array, Program Tids
   *
   * @return array,
   * all Meeting NID
   */
  public function allMeetingNidByProgram($tids = array()) {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'meeting')
      ->propertyCondition('status', NODE_PUBLISHED);

    if (is_array($tids))  {
      $query->fieldCondition('field_meeting_program', 'target_id', $tids, 'IN');
    }

    $result = $query->execute();

    $nid_array = NULL;
    if (isset($result['node'])) {
      if (count($result['node']) > 0 ) {
        $nid_array = array_keys($result['node']);
      }
    }

    return $nid_array;
  }

  /** - - - - - - with condition - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @parameter
   *  array, meeting nids
   *  integer, status tid
   *
   * @return array,
   *  all Meeting NID after filter by Status
   */
  public function allMeetingNidByStatus($all_meeting_nid = array(), $status = NULL) {
    $output = NULL;

    if ($status) {
      if (is_array($all_meeting_nid)) {
        $nodes = node_load_multiple($all_meeting_nid);

        if (is_array($nodes)) {
          foreach($nodes as $node) {
            $MeetingInfo = new MeetingInfo($node);

            if($status == $MeetingInfo->statusTid()) {
              $output[] = $node->nid;
            }
          }
        }
      }
    }

    return $output;
  }

  /**
   * @parameter
   *  array, meeting nids
   *  integer, status tid
   *  integer, specify user uid is node author
   *
   * @return array,
   *  all Meeting NID after filter by Status
   */
  public function allMeetingNidByStatusBySpecifyUser($all_meeting_nid = array(), $status = NULL, $specify_user_uid = NULL) {
    $output = NULL;

    $all_meeting_nid = $this->allMeetingNidByStatus($all_meeting_nid, $status);


    if (is_array($all_meeting_nid)) {
      foreach($all_meeting_nid as $nid) {
        $MeetingInfo = new MeetingInfo($nid);

        if($status == $MeetingInfo->statusTid()) {
          if($MeetingInfo->nodeUid() == $specify_user_uid) {
            $output[] = $nid;
          }
        }
      }
    }

    return $output;
  }

}
