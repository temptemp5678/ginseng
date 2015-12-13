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


  /** - - - - - User  - - - - - - - - - - - - - - - - - - - - - - - - -   */


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
