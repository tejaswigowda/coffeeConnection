
#include <AWS_IOT.h>
#include <WiFi.h>




char* generateClientID () {
  char* cID = new char[23]();
  for (int i = 0; i < 22; i += 1)
    cID[i] = (char)random(1, 256);
  return cID;
}



AWS_IOT hornbill;   // AWS_IOT instance

char WIFI_SSID[]="AriGrading";
char WIFI_PASSWORD[]="12345678";
char HOST_ADDRESS[]="aib4uv366vh79-ats.iot.us-east-1.amazonaws.com";
char *CLIENT_ID= generateClientID();
char TOPIC_NAME[]= "$aws/things/cup_prototype/shadow/update";


int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];


void setup() {
    
    Serial.begin(115200);
    delay(2000);

    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(WIFI_SSID);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        // wait 5 seconds for connection:
        delay(5000);
    }

    Serial.println("Connected to wifi");

    if(hornbill.connect(HOST_ADDRESS,CLIENT_ID)== 0) // Connect to AWS using Host Address and Cliend ID
    {
        Serial.println("Connected to AWS");
        delay(1000);
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);

}


void loop() {

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = 0;// dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = 0;// dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = 0;// dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
    }
    else
    {
        sprintf(payload,"Humidity:%f  Temperature:%f'C",h,t); // Create the payload for publishing
        
        if(hornbill.publish(TOPIC_NAME,payload) == 0)   // Publish the message(Temp and humidity)
        {        
            Serial.print("Publish Message:");   
            Serial.println(payload);
        }
        else
        {
            Serial.println("Publish failed");
        }
        // publish the temp and humidity every 5 seconds.
        vTaskDelay(5000 / portTICK_RATE_MS);     
    } 
}
