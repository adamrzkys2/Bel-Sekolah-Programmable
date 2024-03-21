#include <LiquidCrystal.h>

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(2,3,4);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String hari;
String jam;
String menit;
String detik;
String bulan;
String waktu;
const int reset_pin = 5;
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
void setup(){
  digitalWrite(reset_pin, HIGH);
  pinMode(reset_pin, OUTPUT);
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  //myRTC.setDS1302Time(0,47,15,2,5,9,2023);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Menginisialisasi Booting(Memakan waktu 3-5 Detik)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Tidak mau memulai:"));
    Serial.println(F("1.Coba Reset Arduino "));
    Serial.println(F("2.Please insert the SD card!"));
    Serial.println("Resetting Arduino");
    delay(1000);
    digitalWrite(reset_pin, LOW);
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30
}

void loop() {
  myRTC.updateTime();
  jam=myRTC.hours;
  menit=myRTC.minutes;
  detik=myRTC.seconds;
  bulan=myRTC.month;
  hari=daysOfTheWeek[myRTC.dayofweek];
  
  //Gabungan Variabel
  waktu=jam + ":" + menit + ":" + detik;
  Serial.println("Sekarang Jam :" + waktu);
  Serial.println("Sekarang Hari:" + hari);
  delay(1000); 

  
if ((hari == "Monday") && waktu == "7:0:0"){
  myDFPlayer.play(23);
}
if ((hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "7:0:0") {
    myDFPlayer.play(18);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "7:40:0") {
    myDFPlayer.play(9);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "8:20:0") {
    myDFPlayer.play(9);
}
if ((hari == "Friday") && waktu == "8:25:0") {
    myDFPlayer.play(18);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "9:0:0") {
    myDFPlayer.play(9);
}
if ((hari == "Friday") && waktu == "9:5:0") {
    myDFPlayer.play(9);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "9:40:0") {
    myDFPlayer.play(17);
}
if ((hari == "Friday") && waktu == "9:45:0") {
    myDFPlayer.play(17);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "10:0:0") {
    myDFPlayer.play(19);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "10:40:0") {
    myDFPlayer.play(9);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "11:20:0") {
    myDFPlayer.play(9);
}
if ((hari == "Friday") && waktu == "11:20:0") {
    myDFPlayer.play(17);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday") && waktu == "12:0:0") {
    myDFPlayer.play(17);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "12:50:0") {
    myDFPlayer.play(19);
}
 if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "13:30:0") {
    myDFPlayer.play(9);
} 
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "14:10:0") {
    myDFPlayer.play(9);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday" ) && waktu == "14:50:0") {
    myDFPlayer.play(9);
}
if ((hari == "Monday" || hari == "Tuesday" || hari == "Wednesday" || hari == "Thursday" || hari == "Friday") && waktu == "15:30:0") {
    myDFPlayer.play(20);
} 
  if(Serial.available()>0){
    char data = Serial.read();
    switch(data){
      case '1':
        myDFPlayer.play(1);
        break; 
        case '3':
        myDFPlayer.play(6);
        break;
        case '4':
        myDFPlayer.play(7); 
        break;
        case '5':
        myDFPlayer.play(8);
        break;
        case '6':
        myDFPlayer.play(18);
        break;
        case '2':
        Serial.end();
        delay(1000);
        Serial.begin(9600);
        break;
        case '7':
        myDFPlayer.play(20);
        break;
        case '8':
        myDFPlayer.play(21);
        break;
        case '9':
        myDFPlayer.play(13);
        break;
      default:
        break;
    }  
  }
}
