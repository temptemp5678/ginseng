/**
 * file
 */
(function ($) {
  var basePathUrl = Drupal.settings.basePath;

  /**
   * AngularJS
   */
  var app = angular.module('manageinfoProgramList', []);
  app.controller('manageinfoProgramListController', ['$scope', '$http', function($scope, $http) {
    var jsonFilePath = basePathUrl + 'sites/default/files/json/source/all_program.json';

    $http.get(jsonFilePath)
      .success(function (data) {
         $scope.sourcedata = data;
         // console.log($scope.sourcedata);
      })
      .error(function (data, status, headers, config) {
         //  Do some error handling here
      });

  }]);

})(jQuery);
