#include <MPU9250_asukiaaa.h>
 
#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 19
#define SCL_PIN 18
#endif
 
MPU9250 mySensor;

float prevAX = 0;
float prevAY = 0;
float prevAZ = 0;


float currAX = 0;
float currAY = 0;
float currAZ = 0;

float prevMag = 0;
void setup() {
while(!Serial);
 
Serial.begin(115200);
Serial.println("started");
 
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

 int lastTap = 0;
 
void loop() {

  
mySensor.accelUpdate();


float currAX = mySensor.accelX();
float currAY = mySensor.accelY();
float currAZ = mySensor.accelZ();


float mag = sqrt(sq(currAX-prevAX) + sq(currAY-prevAY) + sq(currAZ-prevAZ));

prevAX = currAX;
prevAY = currAY;
prevAZ = currAZ;

if(mag > 6){
  int now = millis();
  if(now-lastTap > 300){
    //Tap detected
    Serial.println("Tap!!"); Serial.println(mag);
    lastTap = now;
  }
}
/*

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
delay(500);
*/
}
