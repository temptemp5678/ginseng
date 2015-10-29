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
   * @parameter array,
   *
   * @return array,
   * all Notify log NID
   */
  public function allGinsengNid() {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'ginseng')
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

}
