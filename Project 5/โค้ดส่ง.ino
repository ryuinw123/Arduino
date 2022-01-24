#include <SPI.h>
#define SS 10
const unsigned int X_AXIS_PIN = 0;
const unsigned int Y_AXIS_PIN = 1;
const unsigned int Z_AXIS_PIN = 2;
const unsigned int NUM_AXES = 3;
const unsigned int PINS[NUM_AXES] = {
X_AXIS_PIN, Y_AXIS_PIN, Z_AXIS_PIN
};
const unsigned int BUFFER_SIZE = 16;
const unsigned int BAUD_RATE = 9600;
int buffer[NUM_AXES][BUFFER_SIZE];
int buffer_pos[NUM_AXES] = { 0 };
float angle,b;
void setup() {
  // put your setup code here, to run once:
SPI.begin ();
SPI.setClockDivider(SPI_CLOCK_DIV16);
Serial.begin(BAUD_RATE);
}
int get_axis(const int axis) {
delay(1);
buffer[axis][buffer_pos[axis]] = analogRead(PINS[axis]);
buffer_pos[axis] = (buffer_pos[axis] + 1) % BUFFER_SIZE;
long sum = 0;
for (unsigned int i = 0; i < BUFFER_SIZE; i++)
sum += buffer[axis][i];
return round(sum / BUFFER_SIZE);
}
int get_x() { return get_axis(0); }
int get_y() { return get_axis(1); }
int get_z() { return get_axis(2); }
void loop() {
  char c;
  digitalWrite (SS,LOW);
  b = (get_x()-334)/70.0;
  angle=asin(b)*180/3.14;
  int d = angle;
  int z = get_z();
  if (z<346){
  Serial.println (180-angle);
  int d = 180-angle;
  int a =d / 100 + '0';
  int b =(d / 10 )%10 + '0';
  int c = d%10 + '0';
  Serial.print (" a = ");
  Serial.print (a);
  Serial.print (" b = ");
  Serial.print (b);
  Serial.print ( " c = ");
  Serial.println (c);
    SPI.transfer (a);
    SPI.transfer (b);
    SPI.transfer (c);
}
if(z>=346){
  int d = angle;
  Serial.print (d);
  int a =d/10+ '0';
  int b =d%10+'0';
  int c = 0 + '0';
  Serial.print (" a = ");
  Serial.print (a);
  Serial.print (" b = ");
  Serial.print (b);
  Serial.print ( " c = ");
  Serial.println (c);
  SPI.transfer (c);
  SPI.transfer (a);
  SPI.transfer (b);
}

 digitalWrite (SS,HIGH);
 SPI.endTransaction();
}
