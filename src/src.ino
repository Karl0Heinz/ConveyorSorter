#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define SERVO_SIGNAL_PIN 16

// define the duration of the signal in milliseconds
#define STOP                    1500
#define ROTATE_CLOCKWISE        1300
#define ROTATE_COUTNERCLOCKWISE 1700

#define DELAY_FACTOR 100;

#define SSID        "Projekt"
#define PSK         "123456789"
#define MQTT_BROKER "192.168.1.11"

Servo servoMotor;
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(SSID, PSK);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println();
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (byte i = 0; i < length; i++) {
    char tmp = char(payload[i]);
    msg += tmp;
  }
  Serial.println(msg);
}

void setup_mqtt() {
  setup_wifi();
  client.setServer(MQTT_BROKER, 1883);
  client.setCallback(callback);
  
  Serial.print("Connecting to MQTT");
  while(!client.connected()) {
    Serial.print(".");
    client.connect("Unbedingt_immer_ändern");
    delay(100);
  }
  Serial.println();
  Serial.println("Connected");
}

void setup_servo() {
  servoMotor.attach(SERVO_SIGNAL_PIN);

  servoMotor.writeMicroseconds(STOP);
  delay(1000);

  servoMotor.writeMicroseconds(ROTATE_CLOCKWISE);
  delay(1000);

  servoMotor.writeMicroseconds(ROTATE_COUTNERCLOCKWISE);
  delay(1000);
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(MQTT_BROKER, 1883);
  
  setup_servo();
}

void loop() {
  servoMotor.writeMicroseconds(STOP);
  int delayTime = 1000 * (int)(((double) std::rand() / RAND_MAX) * 100);
  Serial.println(delayTime);
  delay(delayTime);
  // delay(2000);

  servoMotor.writeMicroseconds(ROTATE_CLOCKWISE);
  delay(2000);

  servoMotor.writeMicroseconds(ROTATE_COUTNERCLOCKWISE);
  delay(2000);

  if (!client.connected()) {
    Serial.print("Connecting to MQTT");
    while(!client.connected()) {
      Serial.print(".");
      client.connect("Sort");
      delay(100);
    }
    Serial.println();
    Serial.println("Connected");
  }
  client.loop();
  client.publish("home/data", "Hello World");
}
