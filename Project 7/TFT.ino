#include <Ucglib.h>
#include <stdio.h>
#include <DS1302.h>
#include <Time.h>  
Ucglib_ST7735_18x128x160_HWSPI ucg(8, 10, 9);
bool setsec,setmin,sethour,setyear,setmonth,setday,setname;
int year1,month1,date1,sec1,minute1,hour1,name1;
int day1;
int a = 0;
namespace {

const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 7;  // Input/Output
const int kSclkPin = 6;  // Serial Clock

DS1302 rtc(kCePin, kIoPin, kSclkPin);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void Input(){
  while (Serial.available()){
      Time t = rtc.time();
    a=Serial.parseInt();
    if (a ==11111){
      setsec =true;
      Serial.println("setsec");
    }
    if (a<10000 && setsec ==true){
      setsec == false;
      sec1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
      rtc.time(t);
    }
    if (a ==11112){
      setmin =true;
      Serial.println("setsec");
    }
    if (a<10000 && setmin ==true){
      setmin == false;
           minute1=a;
           if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
            rtc.time(t);
    }
    if (a ==11113){
      sethour =true;
      Serial.println("sethour");
    }
    if (a<10000 && sethour ==true){
      sethour == false;
      hour1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
            rtc.time(t);
    }
    if (a ==11114){
      setday =true;
      Serial.println("setday");
    }
    if (a<10000 && setday ==true){
      setday == false;
      date1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
      rtc.time(t);
    }
    if (a ==11115){
      setmonth =true;
      Serial.println("setmonth");
    }
    if (a<10000 && setmonth ==true){
      setmonth == false;
      month1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
            rtc.time(t);
    }
    if (a ==11116){
      setyear =true;
      Serial.println("setyear");
    }
    if (a<10000 && setyear ==true){
      setyear == false;
      year1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
      rtc.time(t);
    }
        if (a ==11117){
      setname =true;
      Serial.println("setname");}
      
      if (a<10000 && setname ==true){
      setname == false;
      day1=a;
      if (day1==1){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSunday);}
      if (day1==2){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kMonday);}
      if (day1==3){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kTuesday);}
      if (day1==4){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kWednesday);}
      if (day1==5){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kThursday);}
      if (day1==6){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kFriday);}
      if (day1==7){
      Time t(year1, month1, date1, hour1,minute1, sec1,Time::kSaturday);}
      rtc.time(t);
    }
  
}}

void printTime() {
  Time t = rtc.time();
  const String day = dayAsString(t.day);
  if (t.sec<=10){
    ucg.clearScreen();
    ucg.setColor(99, 63, 58);
    ucg.setFont(ucg_font_ncenR12_hf);
    ucg.drawFrame(50, 0, 70, 31);
    ucg.setColor(91, 227, 18);
    ucg.setPrintPos (25,30);
    ucg.print ("DATE & DAYS");
    ucg.setPrintPos(5,65);
    ucg.setColor(9, 165, 222);
    ucg.print (t.date);
    ucg.setPrintPos(20,65);
    ucg.setColor(209, 204, 61);
    ucg.print ("/");
    ucg.setPrintPos(30,65);
    ucg.setColor(224, 29, 111);
    ucg.print (t.mon);
    ucg.setPrintPos(50,65);
    ucg.setColor(209, 204, 61);
    ucg.print ("/");
    ucg.setPrintPos(60,65);
    ucg.setColor(201, 48, 28);
    ucg.print (t.yr);
    ucg.setPrintPos (25,110); 
    Serial.println (t.day);
    switch (t.day){
      case (1):
      ucg.setColor(247, 27, 27);
      case (2):
      ucg.setColor(252, 240, 3);
      case (3):
      ucg.setColor(230, 14, 226);
      case (4):
      ucg.setColor(36, 252, 3);
      case (5):
      ucg.setColor(252, 69, 3);
      case (6):
      ucg.setColor(2, 138, 212);
      case (7):
      ucg.setColor(126, 18, 227);
    }
    ucg.setFont(ucg_font_inr21_mr);
    ucg.print (day.c_str());
    delay (11000);
    ucg.clearScreen();
  }
  if (t.sec>10){
  ucg.setColor(128, 0, 128);
  ucg.drawFrame(20, 5, 120, 40);
  ucg.setPrintPos (25,30);
  ucg.setFont(ucg_font_ncenR12_hf);
  ucg.print("Arduino Clock");
  ucg.setColor (0,255,255,255);
  ucg.setColor (1,0,0,0);
  ucg.setPrintPos (5,90);
  ucg.setFont(ucg_font_inr21_mr);
  ucg.print(t.hr);
  ucg.setPrintPos (45,90);
  ucg.print(":");
  ucg.setPrintPos (63,90);
  ucg.print(t.min);
  ucg.setPrintPos (100,90);
  ucg.print(":");
  ucg.setPrintPos (120,90);
  ucg.print(t.sec);}
}}
void setup () {
Serial.begin (9600);
rtc.writeProtect(false);
rtc.halt(false);
//Time t(2019, 11, 5, 22, 34, 0, Time::kTuesday);
//rtc.time(t);
ucg.begin(UCG_FONT_MODE_SOLID);
ucg.clearScreen();
ucg.setRotate90(); 
}
void loop(){  
  printTime();
  Input();
}
