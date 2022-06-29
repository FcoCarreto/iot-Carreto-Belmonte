<html>
  <head>
  <body style="  background: url('https://www.larazon.es/resizer/U9tRac8nUeIGgPWyXDzs-xwX6gE=/600x400/smart/filters:format(jpg)/cloudfront-eu-central-1.images.arcpublishing.com/larazon/ADRBGCX6OJA3ZFHYJND3BJF3Z4.jpg'); background-size: cover;  backdrop-filter: blur(7px);" > <!-- Fondo de la página web -->
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript" src="/assets/js/jquery-3.5.1.min.js"></script>
    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'Id');
        data.addColumn('number', 'Distancia');
        data.addColumn('number', 'Contador');
        data.addColumn('number', 'fecha');

        var options = {
          title: 'Distancia (Centimetros)',
          hAxis: {title: 'Segundos transcurridos',  titleTextStyle: {color: '#333'}},
          vAxis: {minValue: 0}
        };
        var chart = new google.visualization.AreaChart(document.getElementById('chart_div'));
       
        
       $.ajax({
                url:"/datosGraficas",
                type:"GET",
                dataType:"json",
                success:function(datos){ 

                 data.addRows(jsonArray(datos));
                 chart.draw(data,options);
                 
                }
              });
       
      
      }

      function jsonArray(obj) {
            var res = []; 
            for(var i in obj){
              var row = [];
              for(var j in obj[i])
                row.push(parseInt(obj[i][j]));
            res.push(row);
            }
            console.log(res);
            return res;
        }
    </script>



<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
  <script type="text/javascript">
    google.charts.load("current", {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);
    function drawChart() {
      var data = new google.visualization.DataTable();
      data.addColumn('number', 'Id');
        data.addColumn('number', 'Distancia');
        data.addColumn('number', 'Contador');
        data.addColumn('number', 'fecha');
      var view = new google.visualization.DataView(data);
      view.setColumns([0, 1,
                       { calc: "stringify",
                         sourceColumn: 1,
                         type: "string",
                         role: "annotation" },
                       2]);

      var options = {
        title: "Datos de sensor puerta",
        width: 1333,
        height: 500,
        bar: {groupWidth: "95%"},
        legend: { position: "none" },
      };
      var chart = new google.visualization.ColumnChart(document.getElementById("columnchart1"));
      $.ajax({
                url:"/datosGraficas",
                type:"GET",
                dataType:"json",
                success:function(datos){ 

                 data.addRows(jsonArray(datos));
                 chart.draw(data,options);
                 
                }
              });
  }
  function jsonArray(obj) {
            var res = []; 
            for(var i in obj){
              var row = [];
              for(var j in obj[i])
                row.push(parseInt(obj[i][j]));
            res.push(row);
            }
            console.log(res);
            return res;
        }
  </script>
    
  </head>
  <body>
    <div id="chart_div" style="width: 100%; height: 500px;"></div>
    <div id="columnchart1" style="width: 100%; height: 500px;"></div>
  </body>
</html>
