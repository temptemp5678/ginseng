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
  drupal_add_js(drupal_get_path('module', 'shopinfo') .'/ng_js/shopinfo_shop_list.ng.js');

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
      $output .= '<div class="row margin-0 margin-top-12 clear-both">';
        $output .= '<div data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';
          $output .= '<div class="col-xs-6 col-xs-4 col-md-3">';
            $output .= '<img ng-src="{{ row.pictureOneUri }}" class="attachment-shop_catalog wp-post-image" alt="">';
            $output .= '<div class="product-info">';
              $output .= '<span class="category-product">';
                $output .= 'shirts';
              $output .= '</span>';
              $output .= '<span class="price">';
              // $output .= '<span class="amount">{{ row.price }}<sup>33</sup></span>';
              $output .= '</span>';
            $output .= '</div>';
          $output .= '</div>';
        $output .= '</div>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
