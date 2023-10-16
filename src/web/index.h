const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <style>
        .center {
            /* margin-left: auto; */
            /* margin-right: auto;
            margin-top: 10%;
            width: 60%;

            border: 3px solid #73AD21;
            padding: 10px; */
            text-align: center;
            align-items: center;
        }

        .centerDiv {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .card {
            background-color: rgb(54, 54, 54);
            border-radius: 25px;
            /* border: 1px solid rgb(114, 114, 114); */
            padding: 20pt;
            box-shadow: 5pt 8pt 7pt #0c0c0c;
        }
        canvas {
    padding-left: 0;
    padding-right: 0;
    margin-left: auto;
    margin-right: auto;
    display: block;
    width: 800px;
}
    </style>

    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">

    <!-- Optional theme -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css">
    <link rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/css/bootstrap-datetimepicker.min.css" />

    <script src="https://cdnjs.cloudflare.com/ajax/libs/moment.js/2.10.6/moment.min.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

    <script
        src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-datetimepicker/4.17.37/js/bootstrap-datetimepicker.min.js"></script>

    <!-- Toggle -->
    <link href="https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css" rel="stylesheet">
    <script src="https://gitcdn.github.io/bootstrap-toggle/2.2.2/js/bootstrap-toggle.min.js"></script>
    <script type='text/javascript' src="https://cdnjs.cloudflare.com/ajax/libs/fabric.js/1.4.0/fabric.min.js"></script>

    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
</head>

<body style="background-color: rgb(26, 25, 25); color: white;">


    <div class="container">

        <br>

        <div class="container">
            <div class="card center">
                <h1>Light State</h1>
                <BR>
                <input id="toggle-event" type="checkbox" data-toggle="toggle" data-size="large" data-onstyle="success">

                <div class="form-group" style="margin-top: 35px;">
                    <label for="formControlRange">Brightness</label>
                    <input type="range" class="form-control-range" id="formControlRange">
                </div>
            </div>
        </div>

        <br>
        <div class="container">
            <div class="card center">
                <h1>Light Mode</h1>
                <br>
                <button type="button" , class="btn" style="margin:5px; color: black;" onclick="setMode(0);">Off</button>
                <br>
                <button type="button" , class="btn" style="margin:5px; color: black;"
                    onclick="setMode(1);">Couch</button>
                <br>
                <br>
                <button type="button" , class="btn" style="margin:5px; color: black;" onclick="setMode(3);">Blue
                    Wave</button>
                <br>
                <button type="button" , class="btn" style="margin:5px; color: black;" onclick="setMode(4);">Color
                    Wheel</button>
                <br>
                <div>
                    <div style="display: inline;">
                        <button type="button" , class="btn" style="margin:5px; color: black;"
                            onclick="setMode(5);">Solid
                            Color</button>
                    </div>
                    <div style="display: inline;">
                        <input type="color" id="colorPicker" name="body" value="#f6b73c">
                    </div>
                </div>
                <div>
                    <div style="display: inline;">
                        <button type="button" , class="btn" style="margin:5px; color: black;" onclick="setMode(2);">Strobe</button>
                    </div>
                    <div style="display: inline;">
                        <input type="number" step="0.5" class="form-control" value="10" id="strobFreq" style="width: 70px; display: inline;">
                    </div>
                    <div style="display: inline;">
                        <input type="number" step="0.05" class="form-control" value="0.3" id="strobDuty" style="width: 70px; display: inline;">
                    </div>
                </div>
                <!-- <br>
                <button type="button" class="btn btn-primary" data-toggle="modal" data-target="#canModal">
                    Launch demo modal
                  </button> -->
            </div>
        </div>
    </div>

    <!-- <div class="modal /fade" tabindex="-1" id="canModal">
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title">Modal title</h5>
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
                <div class="modal-body">
                    <p id="results">Move mouse over canvas</p>
                    <canvas id=canvas width=300 height=300></canvas>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                    <button type="button" class="btn btn-primary">Save changes</button>
                </div>
            </div>
        </div>
    </div> -->

    <script>

        $(function () {
            $('#toggle-event').change(function () {
                if ($(this).prop('checked')) {
                    setPower(true);
                    console.log("Setting light on");
                }
                else {
                    setPower(false);
                    console.log("Setting light off");
                }
            })
        })

        $(function () {
            $('#dateInput').change(function () {
                var text = document.getElementById("dateInput").innerHTML;
                console.log("Time: " + text)
            })
        })

        function setPower(state) {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "setPower?state=" + (state ? "1" : "0"), true);
            xhttp.send();
        }

        function setBrightness(led) {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "setBrightness?brightness=" + led, true);
            xhttp.send();
        }

        function setMode(mode) {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "setMode?mode=" + mode, true);
            xhttp.send();
        }

        function setStrobeSettings(freq, duty){
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "setStrobeSettings?frequency=" + freq + "&duty=" + duty, true);
            xhttp.send();
        }

        function hexToRgb(hex) {
            var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
            return result ? {
                r: parseInt(result[1], 16),
                g: parseInt(result[2], 16),
                b: parseInt(result[3], 16)
            } : null;
        }

        $('#colorPicker').on('input',
            function () {
                var rgb = hexToRgb($(this).val());

                var xhttp = new XMLHttpRequest();
                var str = "setSolidColor?r=" + rgb.r + "&g=" + rgb.g + "&b=" + rgb.b;
                xhttp.open("GET", str, true);
                xhttp.send();
            }
        );

        $('#strobFreq').on('input',
            function () {
                setStrobeSettings($('#strobFreq').val(), $('#strobDuty').val());
            }
        );
        $('#strobDuty').on('input',
            function () {
                setStrobeSettings($('#strobFreq').val(), $('#strobDuty').val());
            }
        );

        $(document).ready(function () {
            loadData();
            window.onfocus = loadData;
        });

        $(document).on('input', '#formControlRange', function () {
            setBrightness(parseFloat($(this).val()) / 100.0

            );
        });

        function loadData() {
            $.get('getPower', function (data) {
                $("#toggle-event").prop('checked', data == "1").change();
            });

            $.get('getBrightness', function (data) {
                $("#formControlRange").val(data * 100.0)
            });
        }

        // setInterval(function () {
        //     getData();
        // }, 2000); //2000mSeconds update rate








//         var canvas = new fabric.Canvas("canvas");

// canvas.isDrawingMode = true;
// canvas.freeDrawingBrush.width = 5;
// canvas.freeDrawingBrush.color = "#ff0000";

// // get a reference to <p id=results></p>
// // (used to report pixel color under mouse)
// var results = document.getElementById('results');

// // get references to the html canvas element & its context
// var canvasElement = document.getElementById('canvas');
// var ctx = canvasElement.getContext("2d");


// // listen for mouse:move events
// canvas.on('mouse:move', function(e) {

//   // get the current mouse position
//   var mouse = canvas.getPointer(e.e);
//   var x = parseInt(mouse.x);
//   var y = parseInt(mouse.y);

//   // get the color array for the pixel under the mouse
//   var px = ctx.getImageData(x, y, 1, 1).data;

//   // report that pixel data
//   results.innerHTML = 'At [' + x + ' / ' + y + ']: Red/Green/Blue/Alpha = [' + px[0] + ' / ' + px[1] + ' / ' + px[2] + ' / ' + px[3] + ']';

// });
    </script>
</body>

</html>
)=====";