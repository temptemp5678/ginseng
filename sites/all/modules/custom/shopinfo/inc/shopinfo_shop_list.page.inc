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
  drupal_add_css(drupal_get_path('module', 'shopinfo') .'/css/shopinfo_shop_list.css');
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
      $output .= '<div class="row margin-0 margin-top-24 clear-both">';
        $output .= '<div data-ng-repeat="row in sourcedata | filter:inputFilter" class="">';

          $output .= '<div class="col-xs-12 col-sm-6 col-md-4 col-lg-3 margin-top-36">';
            $output .= '<div class="product-info-wrapper box-shadow-6-2 height-380 bg-ffffff">';
              $output .= '<div class="grid">';
                $output .= '<figure class="effect-julia">';
                  $output .= '<img data-ng-src="{{ row.pictureOneUri }}" class="border-bottom-1-f0f2f5" alt="" style="width:100%;height:280px;">';
                $output .= ' </figure>';
              $output .= ' </div>';
              $output .= '<div class="product-info text-center bg-ffffff">';
                $output .= '<div class="color-7b7f81 margin-top-24 ">';
                  $output .= 'shirts';
                $output .= '</div>';
                $output .= '<div class="">';
                  $output .= '<span class="amount">¥{{ row.price }}<sup></sup></span>';
                $output .= '</div>';
                $output .= '<div class="">';
                  $output .= '<span class="amount"><sup>No.{{ row.serial }}</sup></span>';
                $output .= '</div>';
              $output .= '</div>';
            $output .= '</div>';
          $output .= '</div>';

        $output .= '</div>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
