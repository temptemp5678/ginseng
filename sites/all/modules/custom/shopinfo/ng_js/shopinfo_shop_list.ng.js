/**
 * file
 */
var basePathUrl = Drupal.settings.basePath;

/**
 * AngularJS
 */
var app = angular.module('shopList', []);

// 使用factory severice取得JSON文件
app.factory("mainData", ['$http', function($http) {
  // var jsonFilePath = basePathUrl + 'sites/default/files/json/source/all_ginseng.json';
  var jsonFilePath = basePathUrl + 'api/json/node/all-ginseng-data';
  var obj = {};

  // 自建一个函数，来返回$http.get取得的文件内容
  obj.fetchUserDetails = function(){
    return $http.get(jsonFilePath);

    // 使用factory也可以返回post的值
    $http.post(pageUrl, json)
  }

  return obj;
}]);

app.controller('shopListController', ['$scope', '$http', 'mainData', function($scope, $http, mainData) {
  mainData.fetchUserDetails().success(function(data) {
    // 通过mainData传递的值，来设置$scope.userProfile的初始值
    $scope.sourcedata = data.nodes.ginseng;
  })
  .error(function (data, status, headers, config) {
     //  Do some error handling here
  });

}]);

