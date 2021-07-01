#include <Servo.h> // called the library for servo motor//
Servo myservo; //created a virtual object for servo motor i.e myservo//  
int buttonPin = 8; //pin 8//
int pressing = 7; //pin7//
int servoPin = 9; // pin 9//
int ledPin = 10; //pin 10//
int lightin = A0; //analogread for LDR//
int readval;
float lightPin = 0; // intial value is set//
int lightsource = 4;//pin 4//
int buttonState = 0; //intial value of the buttonstate//
int button = 0;//intial value of button//
int value1 = 0;
void setup(){
   // put your setup code here, to run once:
  Serial.begin(9600); //to intialize the serial monitor with baud rate 9600//
  myservo.attach(servoPin); //servo motor  attached to analogwrite pin 9//
  pinMode(buttonPin, INPUT);
  pinMode(pressing, INPUT);
  pinMode(lightin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(lightsource, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(pressing); //light source intiation//
  if (button == HIGH)
  {
  digitalWrite(lightsource, HIGH); //light source will be on when button is pressed//
  }
  else
 {
   digitalWrite(lightsource, LOW);
 }
  
  buttonState = digitalRead(buttonPin); //button pressing (in serial monitor 0-0 5v-1023) so to calculate....//
  if(buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH); 
    for(int i = 0; i <= 9; i = i + 3)   //here i define angle for servo i.e 0 mean zero degree// 
    {
    myservo.write(i);//write the command in servo motor//
    delay(1000);
    }
    for(int i = 9; i <= 24; i = i + 1)
    {
    readval=analogRead(lightin);
    lightPin=(5./1023.)*readval; //conversion:- voltage value(0-5)=(5/1023)*readvalue where read value can be (0-1023)//
    Serial.println(lightPin); //pintln command tells to goto new line//
    delay(250);
    Serial.println(lightPin);
    delay(250);
    Serial.println(lightPin);
    delay(250);
    Serial.println(lightPin);
    delay(250);
    Serial.println(lightPin);
    delay(250);
    myservo.write(i);
    delay(2000);
  }
  else {  
  myservo.write(value1);
  digitalWrite(ledPin, LOW);
  }
}
