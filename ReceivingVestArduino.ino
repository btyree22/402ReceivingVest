#include <Arduino.h>
#include <rf24g.h>
#include <RF24.h>
RF24 radio(32, 34); // CE, CSN
const byte address[6] = "00001";

int motor_pin_1 = 2;
int motor_pin_2 = 3;
int motor_pin_3 = 5;
int motor_pin_4 = 9;
int motor_pin_5 = 10;
int motor_pin_6 = 13;

const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

float delay_time = 0.000000000001;

boolean motor_state_1 = 0;
boolean motor_state_2 = 0;
boolean motor_state_3 = 0;
boolean motor_state_4 = 0;
boolean motor_state_5 = 0;
boolean motor_state_6 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(motor_pin_1, OUTPUT);
    pinMode(motor_pin_2, OUTPUT);
    pinMode(motor_pin_3, OUTPUT);
    pinMode(motor_pin_4, OUTPUT);
    pinMode(motor_pin_5, OUTPUT);
    pinMode(motor_pin_6, OUTPUT);
    
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening(); //sets Arduino as a receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if(radio.available()){
    //if(radio.available() == true){
    //  Serial.println("Radio available");
    //}
    unsigned long data = 0;
    radio.read(&data, sizeof(unsigned long));
    Serial.println(data);
    if(data==1){
      digitalWrite(motor_pin_1, HIGH);
      Serial.print("pin 1");
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
    }
    
    if(data==2){
      digitalWrite(motor_pin_2, HIGH);
      delay(delay_time);
      digitalWrite(motor_pin_2, LOW);
    }
    else{
      digitalWrite(motor_pin_2, LOW);
    }
    
    if(data==3){
      digitalWrite(motor_pin_3, HIGH);
      delay(delay_time);
      digitalWrite(motor_pin_3, LOW);
    }
    else{
      digitalWrite(motor_pin_3, LOW);
    }
    
    if(data==4){
      digitalWrite(motor_pin_4, HIGH);
      delay(delay_time);
      digitalWrite(motor_pin_4, LOW);
    }
    else{
      digitalWrite(motor_pin_4, LOW);
    }
    
    if(data==5){
      digitalWrite(motor_pin_5, HIGH);
      delay(delay_time);
      digitalWrite(motor_pin_5, LOW);
    }
    else{
      digitalWrite(motor_pin_5, LOW);
    }

    if(data==6){
      digitalWrite(motor_pin_6, HIGH);
      delay(delay_time);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_6, LOW);
    }    

    if(data==7){
      digitalWrite(motor_pin_1, HIGH);
      digitalWrite(motor_pin_2, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_2, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_2, LOW);
    }

    if(data==8){
      digitalWrite(motor_pin_1, HIGH);
      digitalWrite(motor_pin_3, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_3, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_3, LOW);
    }

    if(data==9){
      digitalWrite(motor_pin_1, HIGH);
      digitalWrite(motor_pin_4, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_4, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_4, LOW);
    }
    
    if(data==10){
      digitalWrite(motor_pin_1, HIGH);
      digitalWrite(motor_pin_5, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_5, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_5, LOW);
    }

    if(data==11){
      digitalWrite(motor_pin_1, HIGH);
      digitalWrite(motor_pin_6, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_1, LOW);
      digitalWrite(motor_pin_6, LOW);
    }

    if(data==12){
      digitalWrite(motor_pin_2, HIGH);
      digitalWrite(motor_pin_3, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_3, LOW);
    }
    else{
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_3, LOW);
    }

    if(data==13){
      digitalWrite(motor_pin_2, HIGH);
      digitalWrite(motor_pin_4, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_4, LOW);
    }
    else{
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_4, LOW);
    }

    if(data==14){
      digitalWrite(motor_pin_2, HIGH);
      digitalWrite(motor_pin_5, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_5, LOW);
    }
    else{
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_5, LOW);
    }

    if(data==15){
      digitalWrite(motor_pin_2, HIGH);
      digitalWrite(motor_pin_6, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_2, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    if(data==16){
      digitalWrite(motor_pin_3, HIGH);
      digitalWrite(motor_pin_4, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_4, LOW);
    }
    else{
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_4, LOW);
    }

    if(data==17){
      digitalWrite(motor_pin_3, HIGH);
      digitalWrite(motor_pin_5, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_5, LOW);
    }
    else{
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_5, LOW);
    }

    if(data==18){
      digitalWrite(motor_pin_3, HIGH);
      digitalWrite(motor_pin_6, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_3, LOW);
      digitalWrite(motor_pin_6, LOW);
    }

    if(data==19){
      digitalWrite(motor_pin_4, HIGH);
      digitalWrite(motor_pin_5, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_4, LOW);
      digitalWrite(motor_pin_5, LOW);
    }
    else{
      digitalWrite(motor_pin_4, LOW);
      digitalWrite(motor_pin_5, LOW);
    }

    if(data==20){
      digitalWrite(motor_pin_4, HIGH);
      digitalWrite(motor_pin_6, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_4, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_4, LOW);
      digitalWrite(motor_pin_6, LOW);
    }

    if(data==21){
      digitalWrite(motor_pin_5, HIGH);
      digitalWrite(motor_pin_6, HIGH);     
      delay(delay_time);
      digitalWrite(motor_pin_5, LOW);
      digitalWrite(motor_pin_6, LOW);
    }
    else{
      digitalWrite(motor_pin_5, LOW);
      digitalWrite(motor_pin_6, LOW);
    }   
  }
}
