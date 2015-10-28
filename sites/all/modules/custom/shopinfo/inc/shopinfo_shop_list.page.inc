<?php
/**
 * @file for New Client Form
 */

/**
 * callback from hook_menu()
 */
function _shopinfo_shop_list() {
  /**
   * load js
   */
  drupal_add_js(drupal_get_path('module', 'manageinfo') .'/subpage/list/ng_js/manageinfo_question_lib_list.ng.js');

  /**
   * output
   */
  $output = '';

  $output .= '<div data-ng-app="shopList" class="row margin-0">';
    $output .= '<div data-ng-controller="shopListController" class="margin-0">';

      $add_question_path = base_path() . 'manage/question-lib/create';
      /**
       * Top
       */
      $output .= '<div class="">';
        $output .= '<div class="float-left">';
          $output .= t('Search') . ' <input data-ng-model="inputFilter.$">';
        $output .= '</div>';
      $output .= '</div>';

      /**
       * List table
       */
      $output .= '<div class="row margin-0 margin-top-12">';
        $output .= '<div data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
          $output .= '<div class="col-xs-6 col-xs-4 col-md-3">';
          $output .= 'tt';
          $output .= '</div>';
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
              $output .= '<th>' . t('Type') . '</th>';
              $output .= '<th>' . t('Chart') . '</th>';
              $output .= '<th></th>';
            $output .= '</tr>';
          $output .= '</thead>';

          $output .= '<tbody data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
            $output .= '<tr>';
              $output .= '<td>{{ row.questionName }}</td>';
              $output .= '<td>{{ row.fieldName }}</td>';
              $output .= '<td>{{ row.chartTypeName }}</td>';
              $output .= '<td><a href="#"><i class="fa fa-external-link fa-lg"></i></a></td>';
            $output .= '</tr>';

          $output .= '</tbody>';
        $output .= '</table>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
