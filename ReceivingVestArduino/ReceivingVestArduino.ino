#include <Arduino.h>
#include <rf24g.h>
#include <RF24.h>
RF24 radio(7, 53);
const byte address[6] = "00001";

int led_pin_1 = 2;
int led_pin_2 = 5;
int led_pin_3 = 9;
int led_pin_4 = 11;
int led_pin_5 = 13;

const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

boolean button_state_1 = 0;
boolean button_state_2 = 0;
boolean button_state_3 = 0;
boolean button_state_4 = 0;
boolean button_state_5 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(led_pin_1, OUTPUT);
    pinMode(led_pin_2, OUTPUT);
    pinMode(led_pin_3, OUTPUT);
    pinMode(led_pin_4, OUTPUT);
    pinMode(led_pin_5, OUTPUT);

    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening(); //sets Arduino as a receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if(radio.available()){
    unsigned long data = 0;
    radio.read(&data, sizeof(unsigned long));
    Serial.println(data);
    if(data==1){
      digitalWrite(led_pin_1, HIGH);
      delay(50);
      digitalWrite(led_pin_1, LOW);
    }
    else{
      digitalWrite(led_pin_1, LOW);
    }
    
    if(data==2){
      digitalWrite(led_pin_2, HIGH);
      delay(50);
      digitalWrite(led_pin_2, LOW);
    }
    else{
      digitalWrite(led_pin_2, LOW);
    }
    
    if(data==3){
      digitalWrite(led_pin_3, HIGH);
      delay(50);
      digitalWrite(led_pin_3, LOW);
    }
    else{
      digitalWrite(led_pin_3, LOW);
    }
    
    if(data==4){
      digitalWrite(led_pin_4, HIGH);
      delay(50);
      digitalWrite(led_pin_4, LOW);
    }
    else{
      digitalWrite(led_pin_4, LOW);
    }
    
    if(data==5){
      digitalWrite(led_pin_5, HIGH);
      delay(50);
      digitalWrite(led_pin_5, LOW);
    }
    else{
      digitalWrite(led_pin_5, LOW);
    }

    if(data==6){
      digitalWrite(led_pin_1, HIGH);
      digitalWrite(led_pin_2, HIGH);     
      delay(50);
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_2, LOW);
    }
    else{
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_2, LOW);
    }

    if(data==7){
      digitalWrite(led_pin_1, HIGH);
      digitalWrite(led_pin_3, HIGH);     
      delay(50);
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_3, LOW);
    }
    else{
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_3, LOW);
    }

    if(data==8){
      digitalWrite(led_pin_1, HIGH);
      digitalWrite(led_pin_4, HIGH);     
      delay(50);
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_4, LOW);
    }
    else{
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_4, LOW);
    }

    if(data==9){
      digitalWrite(led_pin_1, HIGH);
      digitalWrite(led_pin_5, HIGH);     
      delay(50);
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_5, LOW);
    }
    else{
      digitalWrite(led_pin_1, LOW);
      digitalWrite(led_pin_5, LOW);
    }
    
    if(data==10){
      digitalWrite(led_pin_2, HIGH);
      digitalWrite(led_pin_3, HIGH);     
      delay(50);
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_3, LOW);
    }
    else{
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_3, LOW);
    }

    if(data==11){
      digitalWrite(led_pin_2, HIGH);
      digitalWrite(led_pin_4, HIGH);     
      delay(50);
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_4, LOW);
    }
    else{
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_4, LOW);
    }

    if(data==12){
      digitalWrite(led_pin_2, HIGH);
      digitalWrite(led_pin_5, HIGH);     
      delay(50);
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_5, LOW);
    }
    else{
      digitalWrite(led_pin_2, LOW);
      digitalWrite(led_pin_5, LOW);
    }

    if(data==13){
      digitalWrite(led_pin_3, HIGH);
      digitalWrite(led_pin_4, HIGH);     
      delay(50);
      digitalWrite(led_pin_3, LOW);
      digitalWrite(led_pin_4, LOW);
    }
    else{
      digitalWrite(led_pin_3, LOW);
      digitalWrite(led_pin_4, LOW);
    }

    if(data==14){
      digitalWrite(led_pin_4, HIGH);
      digitalWrite(led_pin_5, HIGH);     
      delay(50);
      digitalWrite(led_pin_4, LOW);
      digitalWrite(led_pin_5, LOW);
    }
    else{
      digitalWrite(led_pin_4, LOW);
      digitalWrite(led_pin_5, LOW);
    }
  }
}
