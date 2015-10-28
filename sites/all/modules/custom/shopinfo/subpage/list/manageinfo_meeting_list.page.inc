<?php
/**
 * @file for New Client Form
 */

/**
 * callback from hook_menu()
 * embed a dash table to show table
 */
function _manageinfo_meeting_list() {
  /**
   * load js
   */
  drupal_add_js(drupal_get_path('module', 'manageinfo') .'/subpage/list/ng_js/manageinfo_meeting_list.ng.js');

  /**
   * output
   */
  $output = '';

  $output .= '<div data-ng-app="manageinfoMeetingList" class="row margin-0">';
    $output .= '<div data-ng-controller="manageinfoMeetingListController" class="row margin-0">';

      /**
       * Top
       */
      $output .= '<div class="">';
        $output .= '<div class="float-left">';
          $output .= t('Search') . ' <input data-ng-model="inputFilter.$">';
        $output .= '</div>';
      $output .= '</div>';

      /**
       * data table
       */
      $output .= '<div class="margin-top-12">';
        $output .= '<table class="table table-hover">';
          $output .= '<thead>';
            $output .= '<tr>';
              $output .= '<th>' . t('Program') . '</th>';
              $output .= '<th>' . t('Date') . '</th>';
              $output .= '<th>' . t('Speaker') . '</th>';
              $output .= '<th>' . t('City') . '</th>';
              $output .= '<th>' . t('Add Evaluation') . '</th>';
            $output .= '</tr>';
          $output .= '</thead>';

          $output .= '<tbody data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
            $output .= '<tr>';
              $output .= '<td>{{ row.programName }}</td>';
              $output .= '<td>{{ row.dateValue }}</td>';
              $output .= '<td>{{ row.speakerName }}</td>';
              $output .= '<td>{{ row.city }}</td>';
              $output .= '<td><a href="{{ row.linkCreateEvaluation}}"><i class="fa fa-external-link fa-lg"></i></a></td>';
            $output .= '</tr>';

          $output .= '</tbody>';
        $output .= '</table>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
