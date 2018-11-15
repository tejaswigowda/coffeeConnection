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

 int lastTap = 0;


#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>

char ssid[] = "Nimbus";          // your network SSID (name)
char pass[] = "richNotComplex";                    // your network password

WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(10,0,1,255);        // remote IP of your computer
const unsigned int outPort = 24333;          // remote port to receive OSC
const unsigned int localPort = 8888;        // local port to listen for OSC packets (actually not used for sending)

void setup() {
    Serial.begin(115200);

    
#ifdef _ESP32_HAL_I2C_H_
// for esp32
Wire.begin(19, 18); //sda, scl
#else
Wire.begin();
#endif
 
mySensor.setWire(&Wire);
 
mySensor.beginAccel();
mySensor.beginMag();



    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
#ifdef ESP32
    Serial.println(localPort);
#else
    Serial.println(Udp.localPort());
#endif

}

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
    OSCMessage msg("/a/tap");
    msg.add(mag);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
    Serial.println("Tap!!"); Serial.println(mag);
    lastTap = now;
  }
}

  //  delay(500);
}
