<?php
/**
 * @file
 *
 */

/**
 * callback from hook_menu()
 */
function _manageinfo_evaluation_create_form_page($meeting_nid = NULL) {
  global $user;

  $form = drupal_get_form('_manageinfo_evaluation_create_form', $meeting_nid);

  $output = '';
  $output .= '<div class="bg-f6f6f6 min-height-650 row margin-0">';
    $output .= '<div class="manage-evaluation-create-wrapper bg-ffffff margin-20">';
      $output .= '<div class="col-md-12 min-height-580">';
        $output .= '<div class="margin-12 margin-top-24 float-left bg-009fe3">';
          // $output .= '<div class="padding-12">';
          //   $output .= '<span class="text-center color-fff">';
          //     $output .= t('Create Evaluation');
          //   $output .= '</span>';
          // $output .= '</div>';
        $output .= '</div>';
        $output .= '<div class="margin-12 float-left clear-both margin-bottom-48">';
          $output .= '<div class="manage-evaluation-create--form-wrapper">';
            $output .= drupal_render($form);
          $output .= '</div>';
        $output .= '</div>';
      $output .= '</div>';
    $output .= '</div>';

  $output .= '</div>';

  return $output;
}

/**
 *  Implements hook_form(), Custom Drupal Form
 */
function _manageinfo_evaluation_create_form($form, &$form_state, $meeting_nid = NULL) {
  drupal_add_css(drupal_get_path('module', 'manageinfo') . '/css/manageinfo_evaluation_create_form.css');

  $meetingInfo = new meetingInfo($meeting_nid);
  $question_array = $meetingInfo->programQuestionSetArray();

  $form['meeting'] = array(
    '#title' => t('Meeting Name'),
    '#type' => 'textfield',
    '#default_value' => $meetingInfo->nodeTitle(),
    '#disabled' => TRUE,
  );

  $form['evaluation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Evaluation'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  foreach ($question_array as $key => $value) {
    $TermQuestionLibInfo = new TermQuestionLibInfo($value['quesset_question_tid']);
    $TermQuestionLibInfo->fieldTid();

    $form['evaluation'][$key] = array(
      '#title' => '<strong>' . $value['quesset_number'] . ' ' . $TermQuestionLibInfo->termName() . '</strong>',
      '#type' => $TermQuestionLibInfo->fieldName(),
    );

    if ($TermQuestionLibInfo->fieldName() == 'radios' || $TermQuestionLibInfo->fieldName() == 'checkboxes') {
      $label_array = $TermQuestionLibInfo->labelTitleValueArray();

      $options = drupal_map_assoc($label_array);
      if ($TermQuestionLibInfo->lengthValue()) {
        $options = array_slice($options, 0, $TermQuestionLibInfo->lengthValue());
      }

      $form['evaluation'][$key]['#options'] = $options;
    }

  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Evaluation'),
  );
  return $form;
}
