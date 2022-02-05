# LED Matrix (100 WS2812 LEDs) 
![Final Product](https://github.com/ShashiWebMax/LED-Matrix/blob/master/photos/final.jpg?raw=true)
## 10x10 WS2812 LED grid display controlled with an ESP8266


### How To Build
**Components**
 - WS2812 Addressable LED (strips are easy to set up) - 100
 - ESP8266
 - 20k potentiometer
 - Push button
 - 5V Power supply (3A or higher)
 -  1 x 10K resistor  

**Building**

 - Wire the led grid as shown in the image ![Matrix Wiring](https://github.com/ShashiWebMax/LED-Matrix/blob/master/photos/wiring.jpg?raw=true)
 - Connect the Grid Signal in wire to ESP8266 pin D1 (GPIO 5)
 - Connect the potentiometer to the analog input (A0) of the ESP. (Rifer [this](https://www.instructables.com/ESP8266-Using-PWM-With-Potentiometer/) guide for more details)
 - Connect the switch to D0 (GPIO 16) of the ESP and pull it down using the resister. (Fifer [this](https://www.instructables.com/Control-LED-Using-PushButton-With-NodeMCU/) guide for more details)
 - Install all the required libraries to Arduino to compile the code 
	 - ESP8266WiFi.h
	 - Adafruit_NeoPixel.h
	 - NTPClient.h
	 - WiFiUdp.h
	 - ESP8266WebServer.h
	 - Adafruit_NeoPixel.h
	 - Adafruit_GFX.h
	 - Adafruit_NeoMatrix.h
	 - Fonts/FreeSerif9pt7b.h
- Set the Wi-Fi Access point  name  and password and upload the code to ESP8266

### How to operate
This Display has 4 Modes
 1. Clock Mode - Obtain the time from internet timeserver and display it
 2. White Light mode - It can be used as a white led light
 3. Red Light mode -  It can be used as a red led light
 4. Display Mode - User can access the web server and give commands to draw anything you like
 5. White Light mode with brightness control - It can be used as a white led light and the brightness can be controlled while display is white

**Use the button to switch between modes**
**Rotate the potentiometer while holding the butten to set the brightness**

## You can use the "LED Matrix.html" file to send display data in the **Display Mode**
- Open the html file using a web browser on a device connected to the same network as the ESP8266.
- Put the Ip address in the Server address input box
- Start sending patterns to draw on the matrix

