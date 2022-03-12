function embrace_math(text) {
  if (text.substr(0, 1) == '`')
    text = "<span class='hidden_element'>" + text + "</span>"
  return text;
}

var app = angular.module('battle', []);
app.controller('RegisterDataController', ['$scope', function ($scope) {
  var right_choice_sfx = new Audio('../sfx/right_choice.wav');
  var wrong_choice_sfx = new Audio('../sfx/wrong_choice.wav');
  
  $scope.players = [];
  $scope.enemies = [];
  $scope.challenges = {
    "start": new Date(),
    "questions": []
  };
  
  $scope.right_choice = function () {
    if (right_choice_sfx)
      right_choice_sfx.play();
  }
  $scope.wrong_choice = function () {
    if (wrong_choice_sfx)
      wrong_choice_sfx.play();
  }
}]);

function RefreshScope()
{
  var scope = angular.element($("body")).scope();
  scope.$apply();
}

function show_results()
{
  destroy_menu();
  
  inner_data[0].menu_shown = false;
  
  results_shown = true;
  
  var scope = angular.element($("body")).scope();
  var challenges = scope.challenges;

    function formatData() {
    var operations = ['Soma','Subtração','Multiplicação','Divisão'];
    
    var wrong_data = [];
    var right_data = [];
    var all_data = [];
    
    var data = [];
    
    for(var i = 0; i < operations.length; i++) {
      var current_wrong_group = {
        "label": operations[i],        
        value:0,
      }
      
      var current_right_group = {
        "label": operations[i],        
        value:0,
      }     

      var current_group = {
        "label": operations[i],        
        value:0,
      }     
      
      for(var j = 0; j < challenges.questions.length; j++) {
        if (challenges.questions[j].operation_index !== i)
          continue;
        current_group.value++;
        if (challenges.questions[j].is_right)
          current_right_group.value++;
        else
          current_wrong_group.value++;
      }

      right_data.push(current_right_group);
      wrong_data.push(current_wrong_group);
      all_data.push(current_group);
    }

    if (true) {
      data.push({
        'key': 'Desafios', 
        'color': "purple",
        'values':all_data
        }
      );
    }
    
    data.push({
      'key': 'Respostas Corretas', 
      'color': "blue",
      'values':right_data
      }
    );
    
    data.push({
      'key': 'Respostas Incorretas',
      'color': "red",
      'values':wrong_data
      }
    );
    return data;
  }        

  nv.addGraph(function() {
  
     //var chart = nv.models.multiBarHorizontalChart()
     var chart = nv.models.multiBarChart()
      .x(function(d) { return d.label })    //Specify the data accessors.
      .y(function(d) { return d.value })
      .showControls(false)
      .transitionDuration(350)
      .reduceXTicks(false)
      .stacked(false);
      

    chart.yAxis
        .tickFormat(d3.format(',d'));

    d3.select('#result_chart svg')
        .datum(formatData())
        .call(chart);

    //nv.utils.windowResize(chart.update);

    return chart;
  });
  
  $('#battle_running').addClass("hidden_element");
  $('#battle_results').removeClass("hidden_element");
  
}

function UpdatePlayer(player_info)
{ 
  player_info = JSON.parse(player_info);
  var scope = angular.element($("body")).scope();
   
  for(var i = 0; i < scope.players.length; i++) {
    if (scope.players[i].Name === player_info.Name) {      
      
      if (player_info.Ready && !scope.players[i].Ready)
        show_menu();
      
      scope.players[i] = player_info; 
      
      RefreshScope();
      return;
    }
  }    

  scope.players.push(player_info);
  RefreshScope();    
}

function UpdateEnemy(enemy_info)
{  
  enemy_info = JSON.parse(enemy_info);
  var scope = angular.element($("body")).scope();
   
  for(var i = 0; i < scope.enemies.length; i++) {
    if (scope.enemies[i].Name === enemy_info.Name) {
      scope.enemies[i] = enemy_info; 
      RefreshScope();
      return;
    }
  }    
  scope.enemies.push(enemy_info);
  RefreshScope();    
}

function Terminate()
{
  window.ExecuteScript('sender:terminate()');
}

if (!window.ExecuteScript) {
  window.ExecuteScript = 
  function(script) {
    console.log("Window.ExecuteScript('"+script+"')");
    show_menu();
  }  
}

function Test()
{
  var max = 40;
  
  function recursive_iterate(i)
  {
    if (i > max) {
      show_results();
      return true;
    }
    console.log("Iteration: "+i)
    show_menu();
    select_menu((i-1)%4)
    setTimeout(function(){recursive_iterate(i+1)}, 110);
    return false;
  }
  
  recursive_iterate(1);
    
 
}