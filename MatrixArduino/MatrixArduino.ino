/* 
WS2812 LED grid
This setup has 4 Modes
  1 = Clock Mode
    - Obtain the time from internet timeserver and display it
  2 = White Light mode
    - It can be used as a white led light
  3 = Red Light mode
    - It can be used as a red led light
  4 = Display Mode
    - User can access the web server and give commands to draw anything you like
  5 = White Light mode with brightness controll
    - It can be used as a white led light and the brightness can be controlled while display is white

* Use the button to switch between modes
* Rotate the potentiometer while holding the butten to set the brightness
* Use the instruction on [xxxxxxx] to build the circuit
* Put your wifi details before uploading

Developed by 
Shashika Kulasekara
Shashi Web Max
kulasekara@hotmail.com
*/

#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Fonts/FreeSerif9pt7b.h>
#include "font.h"

// ---------------------------------- Configuration ---------------------------------
// Server Port 
ESP8266WebServer server(80);

//Setup Wifi connection
const char *ssid = "AP name";
const char *password = "Password";

// Pin used to connect the Matrix
#define PIN 5  
// ---------------------------------- Configuration ---------------------------------       

void handleRoot()
{
  String h_page = "<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'> <title>RGB Grid</title></head><body> <table id='tb'> <tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr> <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr></table> <br><input type='color' id='color' style='width:40%;'> <input type='button' onclick='fill()' value='Fill'style='width:40%; padding:5px; margin:0px'> <br><br>Time : <input type='number' id='time' value='-1'> ms*10 <br><br><input type='range' style='width:100%' min='0' max='255' onchange='brightness(this.value)' value='5'> <div id='out'></div><style>td{border: 1px solid gray; height: 10vw; width: 10vw;}table{border-spacing: 0px;}</style> <script>var default_color='0,0,0,'; let img=[ ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','',''], ['','','','','','','','','','']]; document.getElementById('tb').addEventListener('click',(e)=>{if(!(e.path[0].cellIndex>=0 &&e.path[1].rowIndex>=0)){return;}e.path[0].style.backgroundColor=document.getElementById('color').value; let selected=default_color; if(document.getElementById('color').style !=''){var rgb_data=hexToRgb(document.getElementById('color').value); selected=rgb_data.r+','+rgb_data.g+','+rgb_data.b+',';}img[e.path[1].rowIndex][e.path[0].cellIndex]=selected; draw_out();}); function hexToRgb(hex){var result=/^#?([a-f\\d]{2})([a-f\\d]{2})([a-f\\d]{2})$/i.exec(hex); return result ?{r: parseInt(result[1], 16), g: parseInt(result[2], 16), b: parseInt(result[3], 16)}: null;}function draw_out(){let out=''; img.forEach(row=>{out +='['; row.forEach(col=>{out +='('; out=out+col+')';}); out +=']';}); document.getElementById('out').innerHTML=out; var xhttp=new XMLHttpRequest(); xhttp.open('POST', '/image', true); xhttp.setRequestHeader('Content-Type','application/x-www-form-urlencoded'); xhttp.onreadystatechange=function(){if (this.readyState==4 && this.status==200){var response=this.responseText; console.log(response);}}; var time=+document.getElementById('time').value; if(time>0){var data='image='+out+'&time='+time;}else{var data='image='+out;}xhttp.send(data);}function fill(){var rgb_data=hexToRgb(document.getElementById('color').value); let color=rgb_data.r+','+rgb_data.g+','+rgb_data.b+','; for (let i=0; i < img.length; i++){for (let a=0; a < img[i].length; a++){img[i][a]=color; document.getElementById('tb').rows[i].cells[a].style.backgroundColor=document.getElementById('color').value;}}default_color=color; draw_out();} function brightness(value){console.log(value); var xhttp=new XMLHttpRequest(); xhttp.open('POST', '/brightness', true); xhttp.setRequestHeader('Content-Type','application/x-www-form-urlencoded'); xhttp.onreadystatechange=function(){if (this.readyState==4 && this.status==200){var response=this.responseText; console.log(response);}}; var time=+document.getElementById('time').value; var data='brightness='+value; xhttp.send(data);}</script> </body></html>";
  server.send(200, "text/html", h_page);
}

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
//------------------------------------------------------------------------

int time_counter = 0;


#define NUMPIXELS 100

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(10, 10, PIN,
                                               NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT +
                                                   NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                                               NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
    matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)};


const uint16_t white = matrix.Color(255, 255, 255);
const uint16_t black = matrix.Color(0, 0, 0);



const long utcOffsetInSeconds = 19800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void wifi_time()
{

  if (time_counter == 0)
  {
    Serial.println("Wifi Time");
    matrix.fillRect(0, 0, 10, 5, matrix.Color(100, 204, 255));
    matrix.fillRect(0, 5, 10, 5, matrix.Color(255, 51, 204));
    matrix.show();
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connectiong to wifi");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(2000);
    Serial.print(".");
    if (digitalRead(16))
    {
      return;
    }
  }

  if (time_counter > 100)
  {
    time_counter = 0;

    Serial.println("Time updated");
    timeClient.begin();
    timeClient.update();

    String formattedTime = timeClient.getFormattedTime();
    Serial.println(formattedTime);
    matrix.fillScreen(0);
    matrix.setCursor(0, 5);
    matrix.setTextColor(matrix.Color(255, 153, 0));
    matrix.print(formattedTime);
    matrix.show();
    matrix.setCursor(0, 10);
    matrix.setTextColor(matrix.Color(0, 102, 255));
    matrix.print(formattedTime.substring(3));
    matrix.show();
  }

  delay(100);
  time_counter++;
}

void show_img(const uint16_t img[][10], int duration)
{

  matrix.fillScreen(0);
  for (int row = 0; row < 10; row++)
  {
    for (int col = 0; col < 10; col++)
    {
      matrix.drawPixel(col, row, img[row][col]);
    }
  }
  matrix.show();
  delay(duration);
}

//initial mode
int mode = 1;

//initial brightness
int brightness = 10;

void setup()
{
  //  pixels.begin();
  //  pixels.setBrightness(20);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setTextColor(colors[0]);
  matrix.setFont(&DSEG14_Classic_Bold_5);
  matrix.setTextSize(1);

  matrix.fillRect(0, 0, 10, 5, matrix.Color(0, 204, 255));
  matrix.fillRect(0, 5, 10, 5, matrix.Color(255, 51, 204));
  matrix.setBrightness(map(analogRead(A0), 0, 1023, 0, 255));
  matrix.show();

  Serial.begin(115200);

  pinMode(16, INPUT);

  server.on("/", handleRoot);

  server.onNotFound(handleNotFound);

  server.on("/image", []()
            {
              uint16_t img_data[10][10] = {
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
                  {
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                      black,
                  },
              };
              int row_ofset = 0;
              String segments_data;
              String image = server.arg(0);
              for (int row = 0; row < 10; row++)
              {
                int from = image.indexOf("[", row_ofset);
                int to = image.indexOf("]", row_ofset);
                if (from == -1 || to == -1)
                {
                  String segment = "";
                }
                else
                {
                  String segment = image.substring(from + 1, to);
                  int col_ofset = 0;
                  for (int col = 0; col < 10; col++)
                  {
                    int col_from = segment.indexOf("(", col_ofset);
                    int col_to = segment.indexOf(")", col_ofset);
                    if (col_from == -1 || col_to == -1)
                    {
                    }
                    else
                    {
                      String sub_segment = segment.substring(col_from + 1, col_to);
                      String rgb_data[3];
                      int rgb_offset = 0;
                      for (int rgb_count = 0; rgb_count < 3; rgb_count++)
                      {
                        int rgb_end = sub_segment.indexOf(",", rgb_offset);
                        rgb_data[rgb_count] = sub_segment.substring(rgb_offset, rgb_end);
                        rgb_offset = rgb_end + 1;
                      }
                      img_data[row][col] = matrix.Color(rgb_data[0].toInt(), rgb_data[1].toInt(), rgb_data[2].toInt());
                      segments_data += "[" + String(row) + "]" + "[" + String(col) + "](" + rgb_data[0] + "," + rgb_data[1] + "," + rgb_data[2] + ")";
                      col_ofset = col_to + 1;
                    }
                  }
                  row_ofset = to + 1;
                }
              }
              int time = server.arg(1).toInt();
              show_img(img_data, time);
              String message = "";
              message += "Debug Data:" + segments_data + "\n time:" + String(time);
              message += "\n";
              for (uint8_t i = 0; i < server.args(); i++)
              {
                message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
              }
              server.enableCORS(true);
              server.send(200, "text/plain", message);
            });

  server.on("/brightness", []()
            {
              String bright = server.arg(0);
              matrix.setBrightness(bright.toInt());
              matrix.show();
              server.enableCORS(true);
              server.send(200, "text/plain", "Brightness set from: 0 to: " + bright);
            });
    
  //Reading and setting brightness
  brightness = map(analogRead(A0), 0, 1023, 0, 255);
  matrix.setBrightness(brightness);
}

void loop()
{

  // handling touch butten presses
  if (digitalRead(16))
  {
    if (mode < 5)
    {
      mode++;
    }
    else
    {
      mode = 1;
    }
    Serial.print("Mode selected =");
    Serial.println(mode);
    while (digitalRead(16))
    {
      //Reading and setting brightness
      brightness = map(analogRead(A0), 0, 1023, 0, 255);
      matrix.clear();
      matrix.setBrightness(brightness);
      matrix.setCursor(0, 5);
      matrix.setTextColor(matrix.Color(255, 255, 255));
      matrix.print(String(map(brightness,0,255,0,99)));
      matrix.setCursor(2, 10);
      matrix.setTextColor(matrix.Color(255, 0, 0));
      matrix.print(String(mode));
      matrix.show();
      Serial.println(brightness);
    }
  }

  switch (mode)
  {
  case 2:
    matrix.fillRect(0, 0, 10, 10, matrix.Color(255, 255, 255));
    matrix.show();
    delay(100);
    break;
  case 5:
    matrix.fillRect(0, 0, 10, 10, matrix.Color(255, 255, 255));
    brightness = map(analogRead(A0), 0, 1023, 0, 255);
    matrix.setBrightness(brightness);
    matrix.show();
    delay(100);    
    break;
  case 3:
    matrix.fillRect(0, 0, 10, 10, matrix.Color(255, 0, 0));
    matrix.show();
    delay(100);
    break;
  case 1:
    wifi_time();
    break;
  case 4:
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.print("Connectiong to wifi");
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
    }
    else
    {
      server.begin();
      Serial.println(WiFi.localIP());
      bool server_running = true;
      while (server_running)
      {
        server.handleClient();
        if (digitalRead(16))
        {
          server_running = false;
        }
      }
    }
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(2000);
      Serial.print(".");
      if (digitalRead(16))
      {
        return;
      }
    }
  }
}
