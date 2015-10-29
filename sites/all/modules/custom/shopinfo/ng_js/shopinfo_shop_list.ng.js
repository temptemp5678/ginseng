/**
 * file
 */
(function ($) {
  var basePathUrl = Drupal.settings.basePath;

  /**
   * AngularJS
   */
  var app = angular.module('shopList', []);
  app.controller('shopListController', ['$scope', '$http', function($scope, $http) {
    var jsonFilePath = basePathUrl + 'sites/default/files/all_ginseng.json';
    var jsonFilePath = basePathUrl + 'sites/default/files/json/source/all_ginseng.json';

    $http.get(jsonFilePath)
      .success(function (data) {
         $scope.sourcedata = data.nodes.ginseng;
      })
      .error(function (data, status, headers, config) {
         //  Do some error handling here
      });

  }]);

})(jQuery);
