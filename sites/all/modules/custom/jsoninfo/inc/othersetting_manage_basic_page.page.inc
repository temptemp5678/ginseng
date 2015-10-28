<?php
/**
 * callback from hook_menu()
 */
function _othersetting_manage_basic_page_403() {
  if (!user_is_logged_in()) {
    drupal_goto('user');
    drupal_exit();
  }

  $output = '';
  $output .= '<div class="text-center" style="background-color:#0D2D3D;">
    <p style="height:80px;">&nbsp;</p>
    <p><span class="h1" style="font-size:80px; color:#ffffff;">403</span></p>
    <p>&nbsp;</p>
    <p><span class="h3 margin-top-12" style="color:#e72682;">IT\'S NOT YOU. IT\'S US</span></p>
    <p>&nbsp;</p>
    <p style="color:#ffffff;">We are experiencing some kind of technical problem.</p>
    <p style="color:#ffffff;">Try again later or contact support@flexxia.ca.</p>
    <p style="height:325px;">&nbsp;</p>
    </div>';

  drupal_add_css(drupal_get_path('module', 'othersetting') .'/css/othersetting_manage_basic_page.css');

  return $output;
}

/**
 * callback from hook_menu()
 */
function _othersetting_manage_basic_page_404() {
  $output = '';
  $output = '<div class="text-center" style="background-color:#0D2D3D;">
    <p style="height:80px;">&nbsp;</p>
    <p><span class="h1" style="font-size:80px; color:#ffffff;">404</span></p>
    <p>&nbsp;</p>
    <p><span class="h1 margin-top-12" style="color:#ffffff;">PAGE NOT FOUND</span></p>
    <p>&nbsp;</p>
    <p style="color:#ffffff;">Unfortunately we\'re having trouble loading the page you are looking for.</p>
    <p style="color:#ffffff;">Someone has been alerted and actively working on a solution.</p>
    <p style="color:#ffffff;">In the meantime you can try this....</p>
    <p>&nbsp;</p>
    <p class="text-center">
      <div style="width:240px; height:48px; line-height:40px; background-color:#e72682; color:#ffffff; border:3px solid #ffffff; font-size:18px; text-align:center;" class="text-center margin-auto border-radius-3">';
      $output .= l(t('Go to home page'), 'dashpage/home/index', array('attributes' => array('class' => array('color-fff'))));
      $output .= '</div>
    </p>
    <p style="height:205px;">&nbsp;</p>
    </div>';

  drupal_add_css(drupal_get_path('module', 'othersetting') .'/css/othersetting_manage_basic_page.css');

  return $output;
}
