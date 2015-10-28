<?php
/**
 * @file
 */

/**
 * class
   $UserInfo = new UserInfo($uid);
   $UserInfo->lastLoginTime();
 *
 */
class UserInfo {
  private $uid;
  private $user = NULL;

  /**
   * @parameter is uid
   */
  function __construct($param){
    $this->uid = $param;

    if (is_numeric($param)) {
      $user = user_load($param);
      if ($user) {
        $this->user = $user;
      }
    }
    else if (is_object($param)) {
      if (isset($param->uid)) {
        $this->uid = $param->uid;
        $this->user = $param;
      }
    }
  }

  /** - - - - - user object - - - - - - - - - -  - - - - -   */
  /**
   * @return integer, Uid
   */
  public function randNum($min = 1, $max = 100) {
    $output = rand($min, $max);

    return $output;
  }

  /** - - - - - user object - - - - - - - - - -  - - - - -   */
  /**
   * @return integer, Uid
   */
  public function userUid() {
    $output = NULL;
    if (isset($this->user->uid)) {
      $output = $this->user->uid;
    }
    return $output;
  }
  /**
   * @return String, Name
   */
  public function userName() {
    $output = NULL;
    if (isset($this->user->name)) {
      $output = $this->user->name;
    }
    return $output;
  }
  /**
   * @return String, email
   */
  public function userEmail() {
    $output = NULL;
    if (isset($this->user->mail)) {
      $output = $this->user->mail;
    }
    return $output;
  }
  /**
   * @return Array, integer, Roles RID
   */
  public function userRolesRid() {
    $output = NULL;

    if (isset($this->user->roles)) {
      $output = array_keys($this->user->roles);
    }
    return $output;
  }
  /**
   * @return Array, String, Roles Rid => Role Name
   */
  public function userRolesName() {
    $output = NULL;

    if (isset($this->user->roles)) {
      $output = $this->user->roles;
    }
    return $output;
  }

  /**
   * @return Boolean,
   */
  public function lastLoginTime() {
    $output = NULL;

    if (isset($this->user->login)) {
      if ($this->user->login > 0) {
        $output = TRUE;
      }
    }
    return $output;
  }
  /**
   * @return interger, unix timestamp
   */
  public function lastLoginTimeStamp() {
    $output = NULL;

    if (isset($this->user->login)) {
      $output = $this->user->login;
    }
    return $output;
  }
  /**
   * @return string, date unix stamp
   */
  public function lastLoginTimeFormat($format = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->lastLoginTimeStamp();
    if ($stamp) {
      $output = format_date($stamp, 'custom', $format);
    }
    return $output;
  }
  /**
   * @return string, date unix stamp
   */
  public function lastLoginTimeInterval($format = NULL) {
    if (!$format) {
      $format = "Y-m-d";
    }

    $output = NULL;
    $stamp = $this->lastLoginTimeStamp();
    if ($stamp) {
      $diff = time() - $stamp;
      $output = format_interval($diff, 1);
    }
    return $output;
  }

  /**
   * @return string, like (America/Toronto, America/Vancouver)
   */
  public function timezone() {
    $output = NULL;

    if (isset($this->user->timezone)) {
      $output = $this->user->timezone;
    }
    return $output;
  }

  /** - - - - - user field - - - - - - - - - - - - - - - - - - - - - -   */
  /**
   * @return String, affiliation
   */
  public function affiliation() {
    $output = NULL;

    if (isset($this->user->field_user_affiliation['und'][0]['value'])) {
      $output = $this->user->field_user_affiliation['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String, First Name
   */
  public function firstName() {
    $output = NULL;

    if (isset($this->user->field_user_firstname['und'][0]['safe_value'])) {
      $output = $this->user->field_user_firstname['und'][0]['safe_value'];
    }
    return $output;
  }
  /**
   * @return String, Last Name
   */
  public function lastName() {
    $output = NULL;

    if (isset($this->user->field_user_lastname['und'][0]['safe_value'])) {
      $output = $this->user->field_user_lastname['und'][0]['safe_value'];
    }
    return $output;
  }
  /**
   * @return String,
   */
  public function fullname() {
    $output = NULL;

    $fullname = NULL;
    if ($this->firstName()) {
      $fullname[] = $this->firstName();
    }
    if ($this->lastName()) {
      $fullname[] = $this->lastName();
    }

    if (is_array($fullname)) {
      $output = implode(" ", $fullname);
    }
    else {
      if ($this->user) {
        $output = $this->user->name;
      }
    }

    return $output;
  }
  /**
   * @return String, Title
   */
  public function userTitle() {
    $output = NULL;

    if (isset($this->user->field_user_title['und'][0]['value'])) {
      $output = $this->user->field_user_title['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String,
   */
  public function city() {
    $output = NULL;

    if (isset($this->user->field_user_city['und'][0]['value'])) {
      $output = $this->user->field_user_city['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String, Province Tid
   */
  public function provinceTid() {
    $output = NULL;

    if (isset($this->user->field_user_province['und'][0]['target_id'])) {
      $output = $this->user->field_user_province['und'][0]['target_id'];
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
   * @return String, location is combine city and province
   */
  public function location() {
    $output = NULL;

    $location = array();
    if ($this->city()) {
      $location[] = $this->city();
    }
    if ($this->provinceName()) {
      $location[] = $this->provinceName();
    }

    if (is_array($location)) {
      $output = implode(" ", $location);
    }

    return $output;
  }

  /**
   * @return String, mobile
   */
  public function mobile() {
    $output = NULL;

    if (isset($this->user->field_user_mobile['und'][0]['value'])) {
      $output = $this->user->field_user_mobile['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return String, specialty
   */
  public function specialty() {
    $output = NULL;

    if (isset($this->user->field_user_specialty['und'][0]['value'])) {
      $output = $this->user->field_user_specialty['und'][0]['value'];
    }
    return $output;
  }

  /**
   * @return integer, specialty Rep Name
   */
  public function specialtyRepUid() {
    $output = NULL;

    if (isset($this->user->field_user_specialtyrep['und'][0]['target_id'])) {
      $output = $this->user->field_user_specialtyrep['und'][0]['target_id'];
    }
    return $output;
  }
  /**
   * @return String, specialty Rep Name
   */
  public function specialtyRepFullName() {
    $output = NULL;

    $UserInfo = new UserInfo($this->specialtyRepUid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->fullname();
    }
    return $output;
  }
  /**
   * @return String, specialty Rep Name
   */
  public function specialtyRepEmail() {
    $output = NULL;

    $UserInfo = new UserInfo($this->specialtyRepUid());
    if(!empty($UserInfo)) {
      $output = $UserInfo->userEmail();
    }
    return $output;
  }

  /**
   * @return String, timezoneValue for sepecify user, like (America/Toronto, America/Vancouver)
   */
  public function userTimezoneValue() {
    $output = NULL;

    if ($this->timezone()) {
      $output = $this->timezone();
    }
    else {
      $output = date_default_timezone_get();
    }
    return $output;
  }
  /**
   * @return integer, timezone offset Value for sepecify user,
   * return (-14400 for America/Toronto)
            (-25200 for America/Vancouver)
   */
  public function userTimezoneOffsetValue() {
    $output = NULL;

    if ($this->userTimezoneValue()) {
      $timezone = $this->userTimezoneValue();

      $this_tz = new DateTimeZone($timezone);
      $now = new DateTime("now", $this_tz);
      $output = $this_tz->getOffset($now);
    }

    return $output;
  }

  /**
   * @return array, integer, Speaker Group Tid
   */
  public function userGroupTid() {
    $output = NULL;

    if (isset($this->user->field_user_speakergroup['und'][0]['target_id'])) {
      foreach ($this->user->field_user_speakergroup['und'] as $key => $value) {
        $output[] = $value['target_id'];
      }
    }
    return $output;
  }
  /**
   * @return array, String, Term Name
   */
  public function userGroupName() {
    $output = NULL;

    if (is_array($this->userGroupTid())) {
      foreach ($this->userGroupTid() as $key => $value) {
        $TermInfo = new TermInfo($value);
        $output[] = $TermInfo->termName();
      }
    }
    return $output;
  }


  /** - - - - - user Avatar - - - - - - - - - -  - - - - -   */
  /**
   * @return User avatar
   */
  public function userAvatarImage() {
    $user_avatar = NULL;

    if( isset($this->user->picture) ){
      $file = file_load($this->user->picture->fid);

      if ($file) {
        $image = array(
          'path' => $file->uri,
          'alt' => 'avatar',
          'attributes' => array('class' => 'img-circle'),
          'width' => 48,
          'height' => 48,
        );
        $user_avatar = theme('image', $image);
      }
    }
    return $user_avatar;
  }

}
