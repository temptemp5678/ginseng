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

  /** - - - - - Basic Object - - - - - - - - - -  - - - - -   */
  /**
   * all Methods
   */
  protected function allMethods() {
    $methods = NULL;

    /**
     * similar with  $methods = get_class_methods($this);
     */
    $reflect = new ReflectionClass(get_class($this));
    $methods = $reflect->getMethods(ReflectionProperty::IS_PUBLIC);

    return $methods;
  }

  /**
   * all Methods with filter condition
   */
  protected function allMethodsArray() {
    $output = NULL;

    $methods = $this->allMethods();
    if (is_array($methods)) {
      foreach ($methods as $method) {
        if ($method->name != '__construct') {
          if ($method->name != 'allMethodsValue') {
            $output[] = $method->name;
          }
        }
      }
    }
    return $output;
  }

  /**
   * all Methods value
   * @return, array
     array{
       method1 => value1,
       method2 => value2,
     };
   */
  public function allMethodsValue() {
    $output = array();

    $methods = $this->allMethodsArray();
    if (is_array($methods)) {
      $row = '';
      foreach ($methods as $key => $method) {
        $row[$method] = $this->$method();
      }
      $output = $row;
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
   $GinsengInfo = new GinsengInfo($nid);
   $GinsengInfo->programTid();
 */
class GinsengInfo extends NodeInfo {
  /** - - - - - - field - - - - - - - - - - - - - - - - - - - - - - - - - -  */

  /**
   * @return String
   */
  public function buyer() {
    $output = NULL;
    if (isset($this->node->field_ginseng_buyer['und'][0]['safe_value'])) {
      $output = $this->node->field_ginseng_buyer['und'][0]['safe_value'];
    }
    return $output;
  }

  /**
   * @return Integer
   */
  public function pictureArray() {
    $output = NULL;
    if (isset($this->node->field_ginseng_picture['und'][0]['fid'])) {
      $output = $this->node->field_ginseng_picture['und'];
    }
    return $output;
  }

  /**
   * @return Integer
   */
  public function pictureBasePath() {
    $output = NULL;
    if (isset($this->node->field_ginseng_picture['und'][0]['uri'])) {
      $output = $this->node->field_ginseng_picture['und'][0]['uri'];
    }
    return $output;
  }
  /**
   * @return Integer
   */
  public function pictureOneUri() {
    $output = NULL;
    if (isset($this->node->field_ginseng_picture['und'][0]['uri'])) {
      $path = $this->node->field_ginseng_picture['und'][0]['uri'];
      $output = file_create_url($path);
    }
    return $output;
  }
  /**
   * @return Integer
   */
  public function pictureTwoUri() {
    $output = NULL;
    if (isset($this->node->field_ginseng_picture['und'][1]['uri'])) {
      $path = $this->node->field_ginseng_picture['und'][1]['uri'];
      $output = file_create_url($path);
    }
    return $output;
  }

  /**
   * @return Integer
   */
  public function price() {
    $output = NULL;
    if (isset($this->node->field_ginseng_picture['und'][0]['value'])) {
      $output = $this->node->field_ginseng_picture['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return integer, date unix stamp for quote order time
   */
  public function soldDateUnixStamp() {
    $output = NULL;
    if (isset($this->node->field_ginseng_sold_date['und'][0]['value'])) {
      $output = $this->node->field_ginseng_sold_date['und'][0]['value'];
    }
    return $output;
  }
  /**
   * @return string depeng on parameter format
   */
  public function soldDateValue($format = NULL, $timezone = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->soldDateUnixStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format, $timezone);
    }
    return $output;
  }

  /**
   * @return Integer
   */
  public function soldPrice() {
    $output = NULL;
    if (isset($this->node->field_ginseng_sold_price['und'][0]['value'])) {
      $output = $this->node->field_ginseng_sold_price['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return Integer, Term Tid
   */
  public function statusTid() {
    $output = NULL;
    if (isset($this->node->field_ginseng_status['und'][0]['target_id'])) {
      $output = $this->node->field_ginseng_status['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return Integer, Term Tid
   */
  public function statusName() {
    $output = NULL;

    $TermInfo = new TermInfo($this->statusTid());
    if(!empty($TermInfo)) {
      $output = $TermInfo->termName();
    }

    return $output;
  }

  /** - - - - - - other - - - - - - - - - - - - - - - - - - - - - - - - - -  */

}
