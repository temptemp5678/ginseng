<?php
/**
 * @file for New Client Form
 */

/**
 * callback from hook_menu()
 * embed a dash table to show table
 */
function _manageinfo_program_list() {
  /**
   * load js
   */
  drupal_add_js(drupal_get_path('module', 'manageinfo') .'/subpage/list/ng_js/manageinfo_program_list.ng.js');

  /**
   * output
   */
  $output = '';

  $output .= '<div data-ng-app="manageinfoProgramList" class="row margin-0">';
    $output .= '<div data-ng-controller="manageinfoProgramListController" class="row margin-0">';

    $add_program_path = base_path() . 'manage/program/create';
      /**
       * Top
       */
      $output .= '<div class="">';
        $output .= '<div class="float-left">';
          $output .= t('Search') . ' <input data-ng-model="inputFilter.$">';
        $output .= '</div>';
        $output .= '<div class="float-right padding-right-12">';
          $output .= '<span class="btn btn-primary padding-6-24">';
            $output .= '<a href="' . $add_program_path . '" class="color-fff">' . t('Add Program') . '</a>';
          $output .= '</span>';
        $output .= '</div>';
      $output .= '</div>';

      /**
       * data table
       */
      $output .= '<div class="margin-top-12">';
        $output .= '<table class="table table-hover">';
          $output .= '<thead>';
            $output .= '<tr>';
              $output .= '<th>' . t('Title') . '</th>';
              $output .= '<th>' . t('Unit') . '</th>';
              $output .= '<th>' . t('Type') . '</th>';
              $output .= '<th>' . t('Class') . '</th>';
              $output .= '<th>' . t('Question Set') . '</th>';
              $output .= '<th>' . t('Number') . '</th>';
              $output .= '<th>' . t('Add Meeting') . '</th>';
            $output .= '</tr>';
          $output .= '</thead>';

          $output .= '<tbody data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
            $output .= '<tr>';
              $output .= '<td>{{ row.programName }}</td>';
              $output .= '<td></td>';
              $output .= '<td></td>';
              $output .= '<td></td>';
              $output .= '<td>{{ row.questionSetName }}</td>';
              $output .= '<td>{{ row.questionSetNumber }}</td>';
              $output .= '<td><a href="{{ row.linkCreateMeeting }}"><i class="fa fa-external-link fa-lg"></i></a></td>';
            $output .= '</tr>';

          $output .= '</tbody>';
        $output .= '</table>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
