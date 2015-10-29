<?php

/**
 * class
   OtherCommonJson::encodeJson();
   OtherCommonJson::saveJsonToFile();
 *
 */
class OtherCommonJson {
  /**
   * @return json array
   */
  public static function encodeJson($raw_data = NULL) {
    $json_data = NULL;

    if (is_array($raw_data)) {
      $json_data = drupal_json_encode($raw_data);
    }

    return $json_data;
  }

  /**
   * @param  array.
   *
   * @return Save JSON to Json file
   */
  public static function saveJsonToFile($json_data = NULL, $file_name = NULL) {
    if (!$file_name) {
      return;
    }

    if ($json_data) {
      $file = file_save_data($json_data, 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
    else {
      // put empty content
      $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
  }

  /**
   * @param  array.
   *
   * @return Save Data to Json file
   */
  public static function saveDataToJson($raw_data = NULL, $file_name = NULL) {
    if (!$file_name) {
      return;
    }

    if (is_array($raw_data)) {
      $json_data = OtherCommonJson::encodeJson($raw_data);
      if ($json_data) {
        $file = file_save_data($json_data, 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
      }
      else {
        // put empty content
        $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
      }
    }
    else {
      // put empty content
      $file = file_save_data('', 'public://json/' . $file_name, FILE_EXISTS_REPLACE);
    }
  }
}

/**
 * class
   $SourceJson = new SourceJson();
   $SourceJson->sourceArrayData();
 *
 */
class SourceJson {
  private $vid;

  /** - - - - - Basic Object - - - - - - - - - -  - - - - -   */
  /**
   * @return data Array
   */
  public function sourceArrayData() {
    $output = NULL;

    $output['terms'] = $this->termArrayData();
    $output['users'] = $this->userArrayData();
    $output['nodes'] = $this->nodeOptionData();

    return $output;
  }

  /** - - - - - Term - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  /**
   * @return Term Array data
   * category by bundle
   */
  public function termArrayData() {
    $output = NULL;

    $all_voc = taxonomy_vocabulary_get_names();
    foreach (taxonomy_vocabulary_get_names() as $voc_key => $voc_row) {
      // skip the current loop iteration
      // city tid is 9
      if ($voc_row->vid == 9) {
        continue;
      }

      $all_term_array = taxonomy_get_tree($voc_row->vid);
      $all_term = array();

      if (is_array($all_term_array)) {
        foreach ($all_term_array as $term_key => $term_row) {
          $all_term[$term_row->tid] = array(
            'tid'  => $term_row->tid,
            'name' => $term_row->name,
          );

          // only for city term, add one property
          if ($voc_row->vid == 9) {
            $TermInfo = new TermInfo($term_row->tid);

            $all_term[$term_row->tid] += array(
              'provinceTid' => $TermInfo->provinceTidByCity(),
            );
          }
        }

        $output[$voc_row->machine_name] = array(
          'vid'  => $voc_row->vid,
          'term' => $all_term,
        );
      }
    }

    return $output;
  }

  /**
   * @return Term Program Array data
   */
  public function allProgram() {
    $output = NULL;

    $all_term_array = taxonomy_get_tree(2);

    if (is_array($all_term_array)) {
      foreach ($all_term_array as $term_key => $term_row) {
        $TermProgramInfo = new TermProgramInfo($term_row->tid);

        $output[] = array(
          'programTid'  => $term_row->tid,
          'programName' => $term_row->name,
          'programDescrption' => $TermProgramInfo->termDescription(),
          'questionSetName' => $TermProgramInfo->questionSetName(),
          'questionSetNumber' => count($TermProgramInfo->questionSetArray()),
          'linkCreateMeeting' => base_path() . 'manage/meeting/create/' . $term_row->tid,
        );
      }
    }

    return $output;
  }

  /** - - - - - User  - - - - - - - - - - - - - - - - - - - - - - - - -   */
  /**
   * @return User Array data
   * category by user roles
   */
  public function userArrayData() {
    $output = NULL;

    foreach (entity_load('user') as $key => $row) {
      if ($key > 0) {
        if ($row->status == 1) {
          $UserInfo = new UserInfo($row->uid);

          $output['speaker']['rid'] = 6;
          if (user_has_role(6, $row)) {
            $output['speaker']['user'][$row->uid] = array(
              'affiliation' => $UserInfo->affiliation(),
              'email' => $UserInfo->userEmail(),
              'location' => $UserInfo->location(),
              'mobile' => $UserInfo->mobile(),
              'fullname' => $UserInfo->fullname(),
              'specialty' => $UserInfo->specialty(),
              'specialtyRepEmail' => $UserInfo->specialtyRepEmail(),
              'specialtyRepFullName' => $UserInfo->specialtyRepFullName(),
              'uid' => $row->uid,
              'userGroupTid' => $UserInfo->userGroupTid(),
            );
          }

          $output['rep']['rid'] = 7;
          if (user_has_role(7, $row)) {
            $output['rep']['user'][$row->uid] = array(
              'affiliation' => $UserInfo->affiliation(),
              'email' => $UserInfo->userEmail(),
              'location' => $UserInfo->location(),
              'mobile' => $UserInfo->mobile(),
              'fullname' => $UserInfo->fullname(),
              'specialty' => $UserInfo->specialty(),
              'specialtyRepEmail' => $UserInfo->specialtyRepEmail(),
              'specialtyRepFullName' => $UserInfo->specialtyRepFullName(),
              'uid' => $row->uid,
            );
          }

        }
      }
    }

    return $output;
  }

  /**
   * @return User List data
   * category by user roles
   */
  public function userListData() {
    $output = NULL;

    $province_term_array = taxonomy_get_tree(5);
    $province_term = array();

    // add province option
    if (is_array($province_term_array)) {
      foreach ($province_term_array as $term_key => $term_row) {
        $key_name = 'term_' . $term_row->tid;

        $province_term['province'][$key_name] = array(
          'tid'  => $term_row->tid,
          'name' => $term_row->name,
        );
      }

      $output['terms'] = $province_term;
    }

    foreach (entity_load('user') as $key => $row) {
      if ($key > 0) {
        if ($row->status == 1) {
          $UserInfo = new UserInfo($row->uid);

          $uid_key = 'user_' . $row->uid;

          $output['users']['profile'][$uid_key] = array(
            'affiliation' => $UserInfo->affiliation(),
            'city' => $UserInfo->city(),
            'email' => $UserInfo->userEmail(),
            'firstName' => $UserInfo->firstName(),
            'fullname' => $UserInfo->fullname(),
            'lastName' => $UserInfo->lastName(),
            'location' => $UserInfo->location(),
            'mobile' => $UserInfo->mobile(),
            'provinceName' => $UserInfo->provinceName(),
            'provinceTid' => $UserInfo->provinceTid(),
            'specialty' => $UserInfo->specialty(),
            'specialtyRepEmail' => $UserInfo->specialtyRepEmail(),
            'specialtyRepFullName' => $UserInfo->specialtyRepFullName(),
            'uid' => $row->uid,
            'userName' => $UserInfo->userName(),
            'timezone' => $UserInfo->userTimezoneValue(),
          );
        }
      }
    }

    return $output;
  }


  /** - - - - - Node - - - - - - - - - - - - - - - - - - - - - - - - -   */

  /**
   * generate Meeting Data
   */
  public function allGinsengData() {
    /**
     * data
     */
    $NodeQuery = new NodeQuery();
    $all_ginseng_nid = $NodeQuery->allGinsengNid();

    $nodes = node_load_multiple($all_ginseng_nid);

    /**
     * data row array
     */
    $data_row = array();

    $data_row['nodes'] = array();
    $data_row['nodes']['ginseng'] = array();
    if (is_array($nodes)) {
      foreach($nodes as $node) {
        $GinsengInfo = new GinsengInfo($node);

        $key = 'item-' . $node->nid;
        // table row
        $data_row['nodes']['ginseng'][] = array(
          'nid' => $GinsengInfo->nodeNid(),
          'nodeUid' => $GinsengInfo->nodeUid(),
          'buyer' => $GinsengInfo->buyer(),
          'price' => $GinsengInfo->price(),
          'soldPrice' => $GinsengInfo->soldPrice(),
          'statusTid' => $GinsengInfo->statusTid(),
          'statusName' => $GinsengInfo->statusName(),
          'pictureOneUri' => $GinsengInfo->pictureOneUri(),
          'pictureTwoUri' => $GinsengInfo->pictureTwoUri(),
          'soldDateValue' => $GinsengInfo->soldDateValue('Y-m-d'),
          'soldDateUnixStamp' => $GinsengInfo->soldDateUnixStamp(),
          // 'linkCreateEvaluation' => base_path() . 'manage/evaluation/create-form-page/' . $GinsengInfo->nodeNid(),
        );
      }
    }

    return $data_row;
  }


}
