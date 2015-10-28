<?php
/**
 * @file
   $TermInfo = new TermInfo($tid);
   $TermInfo->provinceTidByCity();
 *
 */

/**
 * class
 */
class TermInfo {
  protected $tid;
  protected $term = NULL;

  /**
   * @parameter is tid
   */
  function __construct($param){

    if (is_numeric($param)) {
      $term = taxonomy_term_load($param);
      if ($term) {
        $this->term = $term;
        $this->tid = $param;
      }
    }
    else if (is_object($param)) {
      if (isset($param->tid)) {
        $this->term = $taxonomy_term_load($param->tid);
        $this->tid = $param->tid;
      }
    }
  }

  /** - - - - - Basic Object - - - - - - - - - -  - - - - -   */
  /**
   * @return Term Name
   */
  public function termName() {
    $output = NULL;
    if ($this->term) {
      $output = $this->term->name;
    }
    return $output;
  }
  /**
   * @return Term Vid
   */
  public function termVid() {
    $output = NULL;
    if ($this->term) {
      $output = $this->term->vid;
    }
    return $output;
  }
  /**
   * @return Term Description
   */
  public function termDescription() {
    $output = NULL;
    if ($this->term) {
      $output = $this->term->description;
    }
    return $output;
  }

}

/**
 * class
   $TermProgramInfo = new TermProgramInfo($tid);
   $TermProgramInfo->questionSetTid();
 */
class TermProgramInfo extends TermInfo {
  /**
   * @return integer, Tid
   */
  public function questionSetTid() {
    $output = NULL;

    if (isset($this->term->field_program_ques_set['und'][0]['target_id'])) {
      $output = $this->term->field_program_ques_set['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, Term Property
   */
  public function questionSetName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->questionSetTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }
  /**
   * @return array,
   */
  public function questionSetArray() {
    $output = NULL;
    if ($this->questionSetTid()) {
      $TermQuestionSetInfo = new TermQuestionSetInfo($this->questionSetTid());
      $output = $TermQuestionSetInfo->questionSetArray();
    }
    return $output;
  }

  /**
   * @return integer, Tid
   */
  public function programTypeTid() {
    $output = NULL;

    if (isset($this->term->field_program_type['und'][0]['target_id'])) {
      $output = $this->term->field_program_type['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, Term Property
   */
  public function programTypeName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->programTypeTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}

/**
 * class
   $TermQuestionLabelInfo = new TermQuestionLabelInfo($tid);
   $TermQuestionLabelInfo->labelTitleArray();
 */
class TermQuestionLabelInfo extends TermInfo {
  /**
   * @return Array,
   */
  public function labelTitleArray() {
    $output = NULL;

    if (isset($this->term->field_queslabel_title['und'][0]['safe_value'])) {
      $output = $this->term->field_queslabel_title['und'];
    }
    return $output;
  }

}

/**
 * class
   $TermQuestionLibInfo = new TermQuestionLibInfo($tid);
   $TermQuestionLibInfo->chartTypeTid();
 */
class TermQuestionLibInfo extends TermInfo {
  /**
   * @return integer,
   */
  public function chartTypeTid() {
    $output = NULL;

    if (isset($this->term->field_queslibr_chart_type['und'][0]['target_id'])) {
      $output = $this->term->field_queslibr_chart_type['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, Term Property
   */
  public function chartTypeName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->chartTypeTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /**
   * @return integer,
   */
  public function fieldTid() {
    $output = NULL;

    if (isset($this->term->field_queslibr_ques_field['und'][0]['target_id'])) {
      $output = $this->term->field_queslibr_ques_field['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, Term Property
   */
  public function fieldName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->fieldTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /**
   * @return integer,
   */
  public function labelTid() {
    $output = NULL;

    if (isset($this->term->field_queslibr_label['und'][0]['target_id'])) {
      $output = $this->term->field_queslibr_label['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return Array,
   */
  public function labelTitleArray() {
    $output = NULL;

    if ($this->labelTid()) {
      $TermQuestionLabelInfo = new TermQuestionLabelInfo($this->labelTid());
      $output = $TermQuestionLabelInfo->labelTitleArray();
    }
    return $output;
  }
  /**
   * @return Array,
   */
  public function labelTitleValueArray() {
    $output = NULL;

    if ($this->labelTitleArray()) {
      foreach ($this->labelTitleArray() as $key => $value) {
        $output[] = $value['safe_value'];
      }
    }
    return $output;
  }

  /**
   * @return integer,
   */
  public function lengthValue() {
    $output = NULL;

    if (isset($this->term->field_queslibr_length['und'][0]['value'])) {
      $output = $this->term->field_queslibr_length['und'][0]['value'];
    }
    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}

/**
 * class
   $TermQuestionSetInfo = new TermQuestionSetInfo($tid);
   $TermQuestionSetInfo->questionCountNumber();
 */
class TermQuestionSetInfo extends TermInfo {
  /**
   * @return integer, for
   */
  public function questionCountNumber() {
    $output = NULL;

    if (isset($this->term->field_quesset_question['und'][0]['quesset_question_tid'])) {
      $output = count($this->term->field_quesset_question['und']);
    }
    return $output;
  }

  /**
   * @return Array
   */
  public function questionSetArray() {
    $output = NULL;
    if (isset($this->term->field_quesset_question['und'][0]['quesset_question_tid'])) {
      $output = $this->term->field_quesset_question['und'];
    }
    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}
