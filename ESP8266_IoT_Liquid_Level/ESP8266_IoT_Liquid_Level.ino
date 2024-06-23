//Required to be on top for Blynk
#define BLYNK_TEMPLATE_ID "TMPL6B3atYUsR"
#define BLYNK_TEMPLATE_NAME "IoT Liquid Level"
#define BLYNK_AUTH_TOKEN "yeD0noOy8EUAsyq5gg3muTrsf-bPtfgz"

#include "config.h"

BlynkTimer timer; // Creating a timer object

void connection_status(){

  // Check if connected to Blynk server
  if (Blynk.connected() && !isConnected) {
    isConnected = true;
    //Serial.println("ESP8266 is connected to Blynk!");
    analogWrite(status_led, 30);
  }
  else if (!Blynk.connected() && isConnected){
    isConnected = false;
    analogWrite(status_led, 0);
  }

}

void liquid_level(int h_pin, int l_pin){
  
  int hardware_pins[] = {h_pin, l_pin}; // Array to hold hardware pins
  int virtual_pins[] = {V0, V1};        // Array to hold virtual pins

  for (int i=0; i<2; i++){
    int status = digitalRead(hardware_pins[i]); // Read the status of the hardware pin
    // Update the virtual pin based on the status
    if (status == 0){
      Blynk.virtualWrite(virtual_pins[i], 0);
    }
    else{
      Blynk.virtualWrite(virtual_pins[i], 1);
    }
  }
}

//defining a wrapper function that takes no arguments and calls
void call_liquid_level() {
  liquid_level(High_Sensor, Low_Sensor);
}

void setup() {

  // Start the Serial Monitor for debugging
  Serial.begin(9600);
  delay(1000);
  Serial.print(version);

  // Setting up pinMode 
  pinMode(High_Sensor, INPUT); pinMode(Low_Sensor, INPUT);
  pinMode(power_led, OUTPUT); analogWrite(power_led, 30);
  pinMode(status_led, OUTPUT); analogWrite(status_led, 0);

  // Setup a function to be called every second
  //This is a pointer funtion 
  timer.setInterval(1000L, call_liquid_level);

  Blynk.begin(auth, ssid, pass);
}

void loop() {

  Blynk.run();
  timer.run();
  connection_status();

}
