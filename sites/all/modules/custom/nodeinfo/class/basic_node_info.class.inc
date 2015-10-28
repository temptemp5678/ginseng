<?php
/**
 * @file
 */

/**
 * class
   $NodeInfo = new NodeInfo($nid);
   $NodeInfo->nodeTitle();
 */
class NodeInfo {
  protected $nid;
  protected $node = NULL;

  /**
   * @parameter is nid or node object
   */
  function __construct($param){
    if (is_numeric($param)) {
      $node = node_load($param);
      if ($node) {
        $this->node = $node;
        $this->nid = $this->node->nid;
      }
    }
    else if (is_object($param)) {
      if (isset($param->nid)) {
        $this->node = $param;
        $this->nid = $this->node->nid;
      }
    }
  }

  /** - - - - - - field - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  public function entityWrapper() {
    $output = NULL;
    if (isset($this->node->nid)) {
      $output = entity_metadata_wrapper('node', $this->node);
    }
    return $output;
  }

  /** - - - - - - basic - - - - - - - - - - - - - - - - - - - - - - - - - -  */
  /**
   * @return String, Node Title
   */
  public function nodeNid() {
    $output = NULL;
    if (isset($this->nid)) {
      $output = $this->nid;
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeTitle() {
    $output = NULL;
    if (isset($this->node->title)) {
      $output = $this->node->title;
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeBody() {
    $output = NULL;
    if (isset($this->node->body['und'][0]['value'])) {
      $output = $this->node->body['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String, Node Title
   */
  public function nodeUid() {
    $output = $this->node->uid;
    return $output;
  }

  /**
   * @return integer, date unix stamp for quote order time
   */
  public function createdUnixStamp() {
    $output = NULL;
    if (isset($this->node->created)) {
      $output = $this->node->created;
    }
    return $output;
  }
  /**
   * @return integer, date unix stamp
   */
  public function createdValue($format = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->createdUnixStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format);
    }
    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}

/**
 * class
   $meetingInfo = new meetingInfo($nid);
   $meetingInfo->programTid();
 */
class meetingInfo extends NodeInfo {
  /** - - - - - - field - - - - - - - - - - - - - - - - - - - - - - - - - -  */

  /**
   * @return Integer, Term Tid
   */
  public function city() {
    $output = NULL;
    if (isset($this->node->field_meeting_city['und'][0]['safe_value'])) {
      $output = $this->node->field_meeting_city['und'][0]['safe_value'];
    }
    return $output;
  }

  /**
   * @return integer, date unix stamp for quote order time
   */
  public function dateUnixStamp() {
    $output = NULL;
    if (isset($this->node->field_meeting_date['und'][0]['value'])) {
      $output = $this->node->field_meeting_date['und'][0]['value'];
    }
    return $output;
  }
  /**
   * @return string depeng on parameter format
   */
  public function dateValue($format = NULL, $timezone = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->dateUnixStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format, $timezone);
    }
    return $output;
  }

  /**
   * @return Integer, Term Tid
   */
  public function programTid() {
    $output = NULL;
    if (isset($this->node->field_meeting_program['und'][0]['target_id'])) {
      $output = $this->node->field_meeting_program['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return Integer, Term Tid
   */
  public function programName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->programTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /**
   * @return Integer, Term Tid
   */
  public function programQuestionSetTid() {
    $output = NULL;
    if ($this->programTid()) {
      $TermProgramInfo = new TermProgramInfo($this->programTid());
      $output = $TermProgramInfo->questionSetTid();
    }
    return $output;
  }
  /**
   * @return array,
   */
  public function programQuestionSetArray() {
    $output = NULL;
    if ($this->programQuestionSetTid()) {
      $TermQuestionSetInfo = new TermQuestionSetInfo($this->programQuestionSetTid());
      $output = $TermQuestionSetInfo->questionSetArray();
    }
    return $output;
  }

  /**
   * @return Integer, Term Tid
   */
  public function provinceTid() {
    $output = NULL;
    if (isset($this->node->field_meeting_province['und'][0]['target_id'])) {
      $output = $this->node->field_meeting_province['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, Term Property
   */
  public function provinceName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->provinceTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /**
   * @return Integer, User Uid
   */
  public function repUid() {
    $output = NULL;
    if (isset($this->node->uid)) {
      $output = $this->node->uid;
    }
    return $output;
  }
  /**
   * @return String, User Property
   */
  public function repName() {
    $output = NULL;

    $UserInfo = new UserInfo($this->repUid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->fullname();
    }

    return $output;
  }
  /**
   * @return String, User Property
   */
  public function repEmail() {
    $output = NULL;

    $UserInfo = new UserInfo($this->repUid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->userEmail();
    }

    return $output;
  }

  /**
   * @return Integer, User Uid
   */
  public function speakerTid() {
    $output = NULL;
    if (isset($this->node->field_meeting_speaker['und'][0]['target_id'])) {
      $output = $this->node->field_meeting_speaker['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, User Property
   */
  public function speakerEmail() {
    $output = NULL;

    $UserInfo = new UserInfo($this->speakerTid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->userEmail();
    }

    return $output;
  }
  /**
   * @return String, User Property
   */
  public function speakerName() {
    $output = NULL;

    $UserInfo = new UserInfo($this->speakerTid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->fullname();
    }

    return $output;
  }
  /**
   * @return String, User Property
   */
  public function speakerLastName() {
    $output = NULL;

    $UserInfo = new UserInfo($this->speakerTid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->lastname();
    }

    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}
