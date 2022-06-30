#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); //(rs,en,d4,d5,d6,d7)
int load_pin=A3;int temp_power=8;
const int temp_sensor=A0;int MQ9=A1;
int MQ2=A2;float load2;int mq2_val;
int mq9_val;int load_val;float tempc; int vout;
void setup(){
pinMode(temp_power,OUTPUT);
digitalWrite(temp_power,HIGH);
pinMode(MQ9,INPUT);
pinMode(MQ2,INPUT);
pinMode(temp_sensor,INPUT);
pinMode(load_pin,INPUT);
lcd.begin(16,2);
Serial.begin(9600); }
void loop() {
load_val=analogRead(load_pin);
mq2_val=analogRead(MQ2);
mq9_val=analogRead(MQ9);
vout=analogRead(temp_sensor);
delay(500);
tempc=vout/10;
tempc=75.00-tempc;
int tempk=tempc*1;
load2=(load_val/10.00)-12;
Serial.print("$");
Serial.print("T");
Serial.print(tempk);
Serial.print("M");
Serial.print(mq9_val);
Serial.print("Q");
Serial.print(mq2_val);
Serial.print("L");
Serial.print(load_val);
Serial.println("#");
lcd.setCursor(0,0);
lcd.print("T=");
lcd.setCursor(2,0);
lcd.print(tempc);
lcd.setCursor(8,0);
lcd.print("MQ9=");
lcd.print(mq9_val);
lcd.setCursor(0,1);
lcd.print("MQ2=");
lcd.print(mq2_val/10);
lcd.print(6,1);
lcd.print("L=");
lcd.print(load2);
}
