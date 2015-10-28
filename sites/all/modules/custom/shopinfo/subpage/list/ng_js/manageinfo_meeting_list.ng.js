/**
 * file
 */
(function ($) {
  var basePathUrl = Drupal.settings.basePath;

  /**
   * AngularJS
   */
  var app = angular.module('manageinfoMeetingList', []);
  app.controller('manageinfoMeetingListController', ['$scope', '$http', function($scope, $http) {
    var jsonFilePath = basePathUrl + 'sites/default/files/json/source/all_meeting.json';

    $http.get(jsonFilePath)
      .success(function (data) {
         $scope.sourcedata = data.nodes.meeting;
         // console.log($scope.sourcedata);
      })
      .error(function (data, status, headers, config) {
         //  Do some error handling here
      });

  }]);

})(jQuery);
