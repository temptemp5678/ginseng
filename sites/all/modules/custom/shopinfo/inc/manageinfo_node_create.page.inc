<?php

/**
 * callback from hook_menu(), modal pop content with AJAX
 */
function _manageinfo_meeting_create() {
  global $user;

  drupal_add_css(drupal_get_path('module', 'manageinfo') . '/css/manageinfo_evalution_create.css');

  $type = 'meeting';
  $form_id = $type . '_node_form';

  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => LANGUAGE_NONE,
  );


  $form_state['build_info']['args'] = array($node);

  form_load_include($form_state, 'inc', 'node', 'node.pages');
  $form = drupal_build_form($form_id, $form_state);

  $form['revision_information']['#access'] = FALSE;
  $form['author']['#access'] = FALSE;



  $output = '';
  $output .= '<div class="bg-f6f6f6 row margin-0">';
    $output .= '<div class="manage-evalution-create-wrapper min-height-580 float-left bg-ffffff margin-20">';
      $output .= '<div class="col-md-12">';
        $output .= '<div class="margin-12 margin-top-24 float-left bg-009fe3">';
          // $output .= '<div class="padding-12 text-center">';
          //   $output .= '<span class="text-center color-fff">';
          //     $output .= t('Create Meeting');
          //   $output .= '</span>';
          // $output .= '</div>';
        $output .= '</div>';
        $output .= '<div class="margin-12 float-left clear-both">';
          $output .= '<div class="manage-evalution-create--form-wrapper">';
            $output .= drupal_render($form);
          $output .= '</div>';
        $output .= '</div>';
      $output .= '</div>';
    $output .= '</div>';

  $output .= '</div>';

  return $output;
}

/**
 * callback from hook_menu(), modal pop content with AJAX
 */
function _manageinfo_evaluation_create() {
  global $user;

  drupal_add_css(drupal_get_path('module', 'manageinfo') . '/css/manageinfo_evalution_create.css');

  $type = 'evaluation';
  $form_id = $type . '_node_form';

  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => LANGUAGE_NONE,
  );

  $form_state['build_info']['args'] = array($node);

  form_load_include($form_state, 'inc', 'node', 'node.pages');
  $form = drupal_build_form($form_id, $form_state);

  $form['revision_information']['#access'] = FALSE;
  $form['author']['#access'] = FALSE;


  $form['field_evaluation_answer']['und']['#cardinality'] = 7;

  $output = '';
  $output .= '<div class="bg-f6f6f6 min-height-650 row margin-0">';
    $output .= '<div class="manage-evalution-create-wrapper bg-ffffff margin-20">';
      $output .= '<div class="col-md-12 min-height-580">';
        $output .= '<div class="margin-12 margin-top-24 float-left bg-009fe3">';
          $output .= '<div class="padding-12 text-center">';
            $output .= '<span class="text-center color-fff">';
              $output .= t('Create Evalution');
            $output .= '</span>';
          $output .= '</div>';
        $output .= '</div>';
        $output .= '<div class="margin-12 float-left clear-both margin-bottom-48">';
          $output .= '<div class="manage-evalution-create--form-wrapper">';
            $output .= drupal_render($form);
          $output .= '</div>';
        $output .= '</div>';
      $output .= '</div>';
    $output .= '</div>';

  $output .= '</div>';

  return $output;
}
