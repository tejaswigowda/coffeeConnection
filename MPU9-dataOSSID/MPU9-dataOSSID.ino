#include <MPU9250_asukiaaa.h>


#include <WiFi.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 19
#define SCL_PIN 18
#endif

String prefix = "FDN-";

MPU9250 mySensor;
 
void setup() {
while(!Serial);
 
Serial.begin(115200);
Serial.println("started");

     WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("Loading...", "lsdjvbnslknv;lsm,v;'");
    WiFi.begin();
    
#ifdef _ESP32_HAL_I2C_H_
// for esp32
Wire.begin(19, 18); //sda, scl
#else
Wire.begin();
#endif
 
mySensor.setWire(&Wire);
 
mySensor.beginAccel();
mySensor.beginMag();
 
// you can set your own offset for mag values
// mySensor.magXOffset = -50;
// mySensor.magYOffset = -55;
// mySensor.magZOffset = -10;
}
 
void loop() {
mySensor.accelUpdate();
Serial.println("print accel values");
Serial.println("accelX: " + String(mySensor.accelX()));
Serial.println("accelY: " + String(mySensor.accelY()));
Serial.println("accelZ: " + String(mySensor.accelZ()));
Serial.println("accelSqrt: " + String(mySensor.accelSqrt()));
 
mySensor.magUpdate();
Serial.println("print mag values");
Serial.println("magX: " + String(mySensor.magX()));
Serial.println("maxY: " + String(mySensor.magY()));
Serial.println("magZ: " + String(mySensor.magZ()));
Serial.println("horizontal direction: " + String(mySensor.magHorizDirection()));
 
Serial.println("at " + String(millis()) + "ms");



  String es = prefix + "_" + String(mySensor.accelX()) + "_" + String(mySensor.accelY()) + "_" + String(mySensor.accelZ()) + "_" + String(mySensor.accelSqrt()) ;//+ "_" +  String(mySensor.magX()) + "_" + String(mySensor.magY()) + "_" +  String(mySensor.magZ());
  Serial.println(es);
  char eschar[32];
  es.toCharArray(eschar,es.length()+1);
  WiFi.softAP(eschar, "jshvckjsncl;skmcv'ds,");
  WiFi.begin();
  
delay(500);
}
