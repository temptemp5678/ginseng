/**
 * file
 */
(function ($) {
  var basePathUrl = Drupal.settings.basePath;

  /**
   * AngularJS
   */
  var app = angular.module('manageinfoQuestionSetList', []);
  app.controller('manageinfoQuestionSetListController', ['$scope', '$http', function($scope, $http) {
    var jsonFilePath = basePathUrl + 'sites/default/files/json/source/all_question_set.json';

    $http.get(jsonFilePath)
      .success(function (data) {
         $scope.sourcedata = data;
      })
      .error(function (data, status, headers, config) {
         //  Do some error handling here
      });

  }]);

})(jQuery);
