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
          $output .= '<li class="product">
                <a href="product-pop-up-content.html" class="view-large-product" rel="gallery">
                  <i class="fa fa-arrows-alt"></i>
                </a>
                <span class="add-to-wish-list">
                  <i class="fa fa-heart"></i>
                </span>
                <a href="product-single.html">
                  <img ng-src="{{ row.pictureOneUri }}" class="attachment-shop_catalog wp-post-image" alt="">
                </a>
                <div class="product-info">
                  <span class="category-product">
                    shirts
                  </span>
                  <a href="product-single.html"><h3>Stripes with floral design</h3></a>
                  <span class="price">
                    <span class="amount">{{ row.price }}<sup>33</sup></span>
                  </span>
                </div>
                <a href="#" rel="nofollow" class="button add_to_cart_button product_type_simple">Add to cart</a>
              </li>';
          $output .= '</div>';
        $output .= '</div>';
      $output .= '</div>';

    $output .= '</div>';
  $output .= '</div>';

  return $output;
}
