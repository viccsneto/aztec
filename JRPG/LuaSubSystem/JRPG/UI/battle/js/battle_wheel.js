
  var data = [
    {
      "value":"1", 
      "onclick": function (){check_data(this);}
    },
    {
      "value":"2", 
      "onclick": function (){check_data(this);}
    },
    {
      "value":"3", 
      "onclick": function (){check_data(this);}
    },
    {
      "value":"4", 
      "onclick": function (){check_data(this);}
    },
  ];
  
  var inner_data = [
    {
      "menu_shown":false,
      "value":"1 + 1", 
    },
  ];
  
  var menu_selected = false;

function check_data(item)
{
  if(!inner_data[0].menu_shown)
	  return;
    

  var scope = angular.element($("body")).scope();
  var challenge_answer = { 
    "user_choose" : item.value,
    "operation_index": inner_data[0].operation_index,
    "expected_value" : inner_data[0].expected_value,
    "math_expression":inner_data[0].value,
    "options": [data[0].value, data[1].value, data[2].value, data[3].value],    
    "is_right": item.value === inner_data[0].expected_value
  };
  
  scope.challenges.questions.push(challenge_answer);
  
  if(challenge_answer.is_right) {
    scope.right_choice();  
    window.ExecuteScript('sender:battle_attack(1)');
  }
  else {
    scope.wrong_choice();  
    window.ExecuteScript('sender:battle_miss(1)');
  }
  destroy_menu();
  RefreshScope();
 
}

var last_random = 1
var occurrences =
	[0,0,0,0];
var occurence_count = 0;

function print_distribution()
{
	var result = "";
	for(var i = 0; i < 4; i++) {
		result += i + " : " + (occurrences[i] / occurence_count) * 100 + "%\n";
	}
		
	console.log(result)
}

function compute_random_right()
{		
  occurence_count++;
	var date = new Date()
	var random_right = (Math.floor((Math.random() * 4) + (Math.random() * (date.getMilliseconds() + (occurence_count*occurence_count*occurence_count))))+(last_random*last_random*last_random)) % 4
	
	
	occurrences[random_right]++;
  last_random = random_right;
	//print_distribution()
  return random_right
}

function raffle_data()
{
  var operations = ["+","-","*","/"];
  var operation_index = Math.floor(Math.random() * operations.length)
  var operation = operations[operation_index];

  var range = operation_index < 2?100:10;
  
  var v1 = Math.floor(Math.random() * range) + 1
  var v2 = Math.floor(Math.random() * range) + 1
  
  if (operation == "/") {
    if (v1 < v2) {
      var aux = v1;
      v1 = v2;
      v2 = aux;
    }
    else {
      var aux = v2;
      v2 = v1;
      v1 = aux;
    }
    while (v1 % v2 !=0) {
      v1++;
    }
  }
  
  inner_data[0].value = v1+ " "+operation+ " "+v2;
  inner_data[0].operation_index = operation_index;
    
  var result = eval(inner_data[0].value);
  
  inner_data[0].expected_value = result;    
  
  var random_right = compute_random_right()
  
  data[random_right].value = result;
  
  var is_valid;
  
  do {
    is_valid = true;
    
    for (var i = 1;i < 4; i++) {   
      var index = (i + random_right) % 4; 
      data[index].value = Math.floor(result * ((Math.random() * 100 + 1)/100)) + i;
    }
    
    for (var i = 0;i < 4 && is_valid; i++) {   
      for (var j = 0;j < 4 && is_valid ; j++) {   
        if (i===j)
          continue;
        if(data[i].value === data[j].value) {
          is_valid = false   
        }
      }
    }    
  } while(!is_valid);       
}

function destroy_menu() 
{
  d3.select("#menu_holder").selectAll("*").remove();
  inner_data[0].menu_shown = false;  
  
}

function show_menu()
{
  if (inner_data[0].menu_shown)
    return;
  
  destroy_menu();
  
  menu_selected = false;
  
  inner_data[0].menu_shown = true;
  raffle_data();
  
  
  var canvas = d3.select("#menu_holder").append("svg")
    .attr("x", "50%")
    .attr("width", 1024)
    .attr("height", 768);
    
  var r = 150;  
  var group = canvas.append("g")
    .attr("transform", "translate(500,300) rotate(45 0 0)");
    
  var arc = d3.svg.arc()
    .innerRadius(r/2)
    .outerRadius(r);   

  var inner_arc = d3.svg.arc()
    .outerRadius(r/2 - 5);
    
    
  var pie = d3.layout.pie()
    .value(function(d){ return 1.0 / data.length;});
    
  var inner_pie = d3.layout.pie()
    .value(function(d){ return 1.0 / inner_data.length;});
    
  var arcs = group.selectAll(".arcgroup")
    .data(pie(data))
    .enter()
    .append("g")
    .classed("arcgroup", true);
    
  function do_click(d) {
    if (d.data.onclick) 
      d.data.onclick();
  }
  
  arcs.append("path")
    .attr("d", arc)
    .attr("fill", "#004")
    .attr("stroke-width", 2)
    .attr("stroke", "white")
    .classed("arc", true)
    .on("click", do_click);
    
    
  arcs.append("text")    
    .attr("transform", function(d) {
        var  c = arc.centroid(d);
        c[0] -= 5;
        c[1] += 15;
        var ret =  "translate(" + c + ") rotate(-45 0 0)";
        return ret;
      })
    .attr("fill", "white")
    .attr("font-size", "16pt")
    .attr("font-weight", "bold")
    .text(function (d) { return +d.data.value;})
    .on("click", do_click);   

  var innerarc = group.selectAll(".innerarc")
    .data(inner_pie(inner_data))
    .enter()
    .append("g")
    .classed("innerarc", true);
    
  innerarc.append("path")
    .attr("d", inner_arc)
    .attr("fill", "rgba(255, 255, 255, 1.0)") //.attr("fill", "rgba(255, 255, 0, 1.0)")
    .attr("stroke-width", 2)
    .attr("stroke", "blue")
    .classed("centerarc", true);    
    
    innerarc.append("text")    
    .attr("transform", function(d) {
        var c = [-(inner_data[0].value.length / 2 * 10.0), 5]
        return "rotate(-45 0 0) translate(" + c +")";}
      )
    .attr("fill", "black")
    .attr("font-size", "16pt")
    .attr("font-weight", "bold")
    .text(function (d) { 
      return d.data.value + " ?";}
    )  
}

function select_menu(idx)
{ 
  
  if (idx < 0 || idx > 3)
    return false;
  
  if (menu_selected)
	  return false;
  
  menu_selected = true;
  
  console.log(idx);
  
  var menu_data = data[idx];
  d3.selectAll(".arc").classed("menu_item_selected", function(d) {
    return d.data === menu_data;}
  );
  setTimeout(function() {
    $(".menu_item_selected").removeClass("menu_item_selected");
    menu_data.onclick();
    
  }, 100);
  return true;
}
