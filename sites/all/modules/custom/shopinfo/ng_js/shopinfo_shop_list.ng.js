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
    var jsonFilePath = basePathUrl + 'sites/default/files/private/json/source/all_question_library.json';

    $http.get(jsonFilePath)
      .success(function (data) {
         $scope.sourcedata = data;
      })
      .error(function (data, status, headers, config) {
         //  Do some error handling here
      });

  }]);

})(jQuery);
