#include "LedControl.h"
#define left 5
#define right 3
bool gameEnable = true;
LedControl lc=LedControl(11,13,10,4); // CLK,DIN,CS,Number of LED Module
unsigned long delaytime=500; // time to updates of the display
int drawx = 3;
int edrawx = 3;
int Down = 4;
long debounceTime = 0;
long bulletdebouncetime=0;
long ebulletdebouncetime=0;
long EdebounceTime = 0;
int bulletline;
int ebulletline;
int ehealth = 4;
int health = 4;
byte gamecon[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte textY[8] = {0x00, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x00};
byte textO[8] = {0x00, 0x7E, 0x7E, 0x66, 0x66, 0x7E, 0x7E, 0x00};
byte textU[8] = {0x00, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x7E, 0x00};
byte textL[8] = {0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00};
byte textS[8] = {0x00, 0x3C, 0x62, 0x38, 0x0C, 0x66, 0x3C, 0x00};
byte textE[8] = {0x00, 0x7E, 0x40, 0x7E, 0x7E, 0x40, 0x7E, 0x00};
byte textW[8] = {0x00, 0x42, 0x42, 0x5A, 0x5A, 0x5A, 0x7E, 0x00};
byte textI[8] = {0x00, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00};
byte textN[8] = {0x00, 0x46, 0x66, 0x76, 0x6E, 0x66, 0x62, 0x00};
byte full[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
void setup() {
int devices=lc.getDeviceCount(); // find no of LED modules
//we have to init all devices in a loop
for(int address=0;address<devices;address++) { // set up each device
lc.shutdown(address,false);
lc.setIntensity(address,8);
lc.clearDisplay(address);//โคดครู
}


//////
draw_ship(drawx);
draw_eship(edrawx);
pinMode (left,INPUT);
pinMode (right,INPUT);
pinMode (Down,INPUT);
}
void loop(){
  int RandomMovement = rand() % 100 + 1;
  while (ehealth != 0 &&millis() - EdebounceTime > 200 && RandomMovement <50 && edrawx <6&& health !=0 && gameEnable == true){//ไปซ้าย
    EdebounceTime = millis ();
    delete_eship (edrawx);    edrawx++;
    draw_eship(edrawx);}
   while (ehealth !=0 &&millis() - EdebounceTime > 200 && RandomMovement >50 && edrawx >1&& health !=0 && gameEnable == true){//ไปขวา
    EdebounceTime = millis ();
    delete_eship (edrawx);
    edrawx--;
    draw_eship(edrawx);}
    while (ehealth !=0 && millis()-ebulletdebouncetime > 2000&& health !=0 && gameEnable == true){
      ebulletdebouncetime = millis();
      ebullet(edrawx);
      if (drawx == edrawx){
      lc.setLed(3,edrawx,1,true);
      lc.setLed(3,edrawx,0,true);
      health--;
      }
      if (edrawx == drawx+1){
      lc.setLed(3,drawx+1,0,true);
      health--;
      }
      if (edrawx == drawx-1){
      lc.setLed(3,drawx-1,0,true);
      health--;
      }
    }
  if (digitalRead(left) == LOW && drawx <6 && millis() - debounceTime > 200 && gameEnable  ==true){
    debounceTime = millis();
    delete_ship (drawx);
    drawx++;
    draw_ship(drawx);}
    if (digitalRead(right) == LOW && drawx > 1 && millis() - debounceTime>200 && gameEnable == true){
    debounceTime = millis();
    delete_ship (drawx);
    drawx--;
    draw_ship(drawx);
    }
    if (digitalRead(Down) == LOW && millis()-bulletdebouncetime > 200 && gameEnable == true){
      bulletdebouncetime= millis();
      bullet (drawx);
      if (drawx == edrawx){
         lc.setLed(0,edrawx,6,true);
         lc.setLed(0,edrawx,7,true);
         ehealth--;
      }
      if (drawx == edrawx+1){
        lc.setLed(0,edrawx+1,7,true);
        ehealth--;
      }
      if (drawx == edrawx-1){
        lc.setLed(0,edrawx-1,7,true);
        ehealth--;
      }
    }
    if (health == 0 && gameEnable == true){
    gameEnable = false;
    start (gamecon);
    start(textL);
    delay(300);
    start(textO);
    delay(300);
    start(textS);
    delay(300);
    start(textE);
    delay(300);
    start(full);
    delay(2000);
    start (gamecon);
    }
    if (ehealth == 0 && gameEnable == true){
    gameEnable = false;
    start (gamecon);
    start(textW);
    delay(300);
    start(textI);
    delay(300);
    start(textN);
    delay(300);
    start(full);
    delay(2000);
    start (gamecon);
    }
    if (ehealth == 4 && health !=0 && gameEnable ==true){
      lc.setLed(1,7,5,true);
      lc.setLed(1,7,4,true);
      lc.setLed(1,7,3,true);
      lc.setLed(1,7,2,true);
    }
    if (ehealth == 3 && health !=0 && gameEnable == true){
      lc.setLed(1,7,5,false);
    }
    if (ehealth == 2 && health !=0 && gameEnable ==true){
      lc.setLed(1,7,4,false);
    }
    if (ehealth == 1 && health !=0 && gameEnable == true){
      lc.setLed (1,7,3,false);
    }
    if (health == 4 && ehealth !=0 && gameEnable ==true){
      lc.setLed(2,7,5,true);
      lc.setLed(2,7,4,true);
      lc.setLed(2,7,3,true);
      lc.setLed(2,7,2,true);
    }
    if (health == 3 && ehealth !=0 && gameEnable == true){
      lc.setLed(2,7,5,false);
    }
    if (health == 2&& ehealth !=0 && gameEnable == true){
      lc.setLed(2,7,4,false);
    }
    if (health == 1&& ehealth !=0 && gameEnable == true){
      lc.setLed (2,7,3,false);
    }
    if (health == 0 || ehealth == 0 && gameEnable == true){
      lc.setLed(2,7,5,false);
      lc.setLed(2,7,4,false);
      lc.setLed(2,7,3,false);
      lc.setLed(2,7,2,false);
      lc.setLed(1,7,5,false);
      lc.setLed(1,7,4,false);
      lc.setLed(1,7,3,false);
      lc.setLed(1,7,2,false);
    }
}
void bullet (int drawx){
  for (int i = 3 ; i < 8 ;i++){
      lc.setLed(3,drawx,i,true);
      delay (20);
      lc.setLed(3,drawx,i,false);
  }
    for (int row = 2; row >=0;row--){
    for (bulletline = 0 ; bulletline <8 ;bulletline++){
      lc.setLed(row,drawx,bulletline,true);
      delay (20);
      lc.setLed(row,drawx,bulletline,false);
    }
  }
}
void draw_eship(int edrawx){
  lc.setLed(0,edrawx,6,true);
  lc.setLed(0,edrawx,7,true);
  lc.setLed(0,edrawx+1,7,true);
  lc.setLed(0,edrawx-1,7,true);
}
void draw_ship(int drawx){
  lc.setLed(3,drawx,1,true);
  lc.setLed(3,drawx,0,true);
  lc.setLed(3,drawx+1,0,true);
  lc.setLed(3,drawx-1,0,true);
}
void delete_ship(int drawx){
  lc.setLed(3,drawx,1,false);
  lc.setLed(3,drawx,0,false);
  lc.setLed(3,drawx+1,0,false);
  lc.setLed(3,drawx-1,0,false);
}
void delete_eship(int edrawx){
  lc.setLed(0,edrawx,6,false);
  lc.setLed(0,edrawx,7,false);
  lc.setLed(0,edrawx+1,7,false);
  lc.setLed(0,edrawx-1,7,false);
}
void start(byte test[]) {
  for (int Clear = 0; Clear<=3 ;Clear ++){
    for (int i = 0; i < 8; i++){
      lc.setRow(Clear, i, test[i]);
    }
  }
  }
void ebullet (int edrawx){
  for (int i = 5 ; i >= 0 ;i--){
      lc.setLed(0,edrawx,i,true);
      delay (20);
      lc.setLed(0,edrawx,i,false);}
      for (int row = 1 ; row <=3; row ++){
      for (int b= 7;b>=0;b--){
      lc.setLed(row,edrawx,b,true);
      delay (20);
      lc.setLed(row,edrawx,b,false);
      }}}
 
