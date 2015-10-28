<?php
/**
 * @file
 */

/**
 * class
   $SettingInfo = new SettingInfo();
   $SettingInfo->siteLogoImage();
 */
class SettingInfo {
  /**
   * @return site logo
   */
  public function siteLogoImage() {
    $logo_image = NULL;
    if (theme_get_setting('logo')) {
      $image = array(
        'path' => theme_get_setting('logo'),
        'alt' => 'Site Logo',
        'attributes' => array('class' => 'site-logo'),
      );
      $logo_image = theme('image', $image);
    }

    return $logo_image;
  }

  /**
   * @return site logo
   */
  public function siteLogoHTML() {
    $logo_image = $this->siteLogoImage();

    $output = NULL;
    if ($logo_image) {
      $output .= '<div class="color-fff">';
        $output .= $logo_image;
      $output .= '</div>';
    }
    return $output;
  }

}

/**
 * class
   $BasicClass = new BasicClass();
   $BasicClass::camelCase();
 */
class BasicClass {
  /**
   * convert a string to a camel case string
   */
  public static function camelCase($str, $noStrip = array()) {
    // non-alpha and non-numeric characters become spaces
    $str = preg_replace('/[^a-z0-9' . implode("", $noStrip) . ']+/i', ' ', $str);
    $str = trim($str);
    // uppercase the first character of each word
    $str = ucwords($str);
    $str = str_replace(" ", "", $str);
    $str = lcfirst($str);

    return $str;
  }
}
