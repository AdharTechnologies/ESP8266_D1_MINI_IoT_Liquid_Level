/*

void author(){
  Embedded CTG
  Facebook:https://web.facebook.com/p/Embedded-CTG-61558436573900/?mibextid=ZbWKwL&_rdc=1&_rdr
  Youtube: https://www.youtube.com/@EmbeddedCTG 
}

void version_hist(){
  version 0 | 2024/06/24
}

void license(){
  MIT License

  Copyright (c) 2024 AdharTechnologies

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
}
*/

//Including Libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "mi_x5";
char pass[] = "proxywarpart1";

//Defining Pins
#define power_led 14 //D5
#define status_led 16 //D0
#define High_Sensor 12 //D6 
#define Low_Sensor 15 //D8 

bool isConnected = false; // Flag to check connection status

String version = "ESP8266_D1_Mini IoT Liquid Level | version 0";