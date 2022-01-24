//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
//Sourceโค้ดที่ส่งไปอันแรกช่องReportมันผิดพลาดครับ เผลอกดไฟล์ผิดไป
#include <DS1302.h>
#include <Time.h>  
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
const int pinCs = 10;
const int numbOfRow  = 1;
const int numbOfCol = 4;
int x = 1;
long debounce = 0;
Max72xxPanel matrix = Max72xxPanel(pinCs,numbOfRow,numbOfCol);
String hour1,hour2,min1,min2,sec1,sec2,timer;
namespace {

const int kCePin   = 5; 
const int kIoPin   = 7; 
const int kSclkPin = 6; 

DS1302 rtc(kCePin, kIoPin, kSclkPin);


void lightpress(){
 if (digitalRead(1)==HIGH && millis()-debounce > 200 ){
    debounce = millis();
    matrix.setIntensity(x+1);
    x++;
  }
  if (digitalRead(2)==HIGH && millis() - debounce > 200){
    debounce = millis();
    matrix.setIntensity (x-1);
    x--;
  }
}


void showText (String myString){
  matrix.setCursor (1,0);
  matrix.fillScreen(LOW);
  matrix.print (myString);
  matrix.write ();
}
void printTime() {
  Time t = rtc.time();
  hour1 = t.hr/10;
  hour2 = t.hr%10;
  min1=t.min/10;
  min2=t.min%10;
  timer = hour1+hour2+':'+min1+min2;
  Serial.println(timer);
}}


void setup() {

  Serial.begin(9600);
  matrix.setIntensity(1);
  matrix.setRotation(1);
  pinMode(1,INPUT);
  pinMode (2,INPUT);
  rtc.writeProtect(false);
  rtc.halt(false);
//  Time t(0, 0, 0, 0, 0, 0, Time::kTuesday);
//  rtc.time(t);
  
}

void loop() {
  printTime();
  showText(timer);
  lightpress();
}
