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
