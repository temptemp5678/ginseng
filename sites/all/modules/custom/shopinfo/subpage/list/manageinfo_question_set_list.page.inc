<?php
/**
 * @file for New Client Form
 */

/**
 * callback from hook_menu()
 * embed a dash table to show table
 */
function _manageinfo_question_set_list() {
  /**
   * load js
   */
  drupal_add_js(drupal_get_path('module', 'manageinfo') .'/subpage/list/ng_js/manageinfo_question_set_list.ng.js');

  /**
   * output
   */
  $output = '';

  $output .= '<div data-ng-app="manageinfoQuestionSetList" class="row margin-0">';
    $output .= '<div data-ng-controller="manageinfoQuestionSetListController" class="row margin-0">';

      $add_set_path = base_path() . '#';
      /**
       * Top
       */
      $output .= '<div class="">';
        $output .= '<div class="float-left">';
          $output .= t('Search') . ' <input data-ng-model="inputFilter.$">';
        $output .= '</div>';
        $output .= '<div class="float-right padding-right-12">';
          $output .= '<span class="btn btn-primary padding-6-24">';
            $output .= '<a href="' . $add_set_path . '" class="color-fff">' . t('Add Set') . '</a>';
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
              $output .= '<th>' . t('Descrption') . '</th>';
              $output .= '<th>' . t('Number') . '</th>';
              $output .= '<th></th>';
            $output .= '</tr>';
          $output .= '</thead>';

          $output .= '<tbody data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
            $output .= '<tr>';
              $output .= '<td>{{ row.questionSetName }}</td>';
              $output .= '<td>{{ row.questionSetDescrption }}</td>';
              $output .= '<td>{{ row.questionCountNumber }}</td>';
              $output .= '<td><a href="#"><i class="fa fa-external-link fa-lg color-3e3e3e opacity-05"></i></a></td>';
            $output .= '</tr>';

          $output .= '</tbody>';
        $output .= '</table>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
