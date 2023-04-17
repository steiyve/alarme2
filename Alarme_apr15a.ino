#include "arduino_secrets.h"
int redPin = 16;
int yellowPin = 17;
int greenPin = 18;
int pirPin = 2;
int buzzer = 21;

int pirValue; 
bool arm = false;
bool verf = false;


#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500);
  initProperties();
  
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, HIGH);

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  bool alarme = false;
  bool arme = false;
  bool arm = false;

  ArduinoCloud.update();

  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  
}



void loop() {
  ArduinoCloud.update();
  pirValue = digitalRead(pirPin);
  
  while()
}


void onArmeChange(){
  
  if(arme==false){
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    alarme = false;
  }
  
  if(arme==true){
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(10000);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    
    arm = true;
  }
  
  
  
}

void onAlarmeChange(){
  if(alarme==true){
    digitalWrite(redPin, HIGH);
    digitalWrite(buzzer, HIGH);
  }
    
  if(alarme==false){
    digitalWrite(redPin, LOW);
    digitalWrite(buzzer, LOW);
  }
}
