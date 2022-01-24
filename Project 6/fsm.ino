#define LED_W_R 4
#define LED_W_Y 5
#define LED_W_G 6
#define WEST_BUTTON_PIN 2
#define LED_S_R 8
#define LED_S_Y 9
#define LED_S_G 10
#define SOUTH_BUTTON_PIN 3
#define goldE 0
#define waitE 1
#define goldN 2
#define waitN 3
#define walk 4
#define WALK_BUTTON_PIN 13
#define led_goldEalk 11
#define led_waitEalk 12
#define STATEgo1 6
#define STATEgo2 7
#define STATEgo3 9
#define STATEgo4 10
#define STATEgo 5
#define STATEgo5 8

struct State {
  unsigned long ST_Out; // binary pattern to street output
  unsigned long Time; // delay in ms units
  unsigned long Next[9];
}; // next state for inputs 0,1,2,3

typedef const struct State SType;

SType FSM[11] = {
  {B10001100, 2000, {goldE, goldE, waitE, waitE, waitE ,waitE, waitE ,waitE}},//สีเขียวของฝั่ง ไม่มีทางเดิน 0 goldE
  {B10001010, 600, {goldN, walk, goldN, goldN, walk, walk, walk ,goldN}},//สีเหลืองของฝั่งไม่มีตนเดิน 1 //แก้ walk 1 waitE
  {B10100001, 2000, {goldN, waitN, goldN, waitN, waitN , waitN, waitN ,waitN}},//สีเขียวของฝั่งที่มีคนเดิน 2 goldN
  {B10010001, 600, {goldE, goldE, goldE, goldE, walk, walk, walk ,walk}},//สีเหลืองของฝั่งที่มีคนเดิน 3 waitN
  {B01001001, 2000, {walk, STATEgo, STATEgo5, STATEgo, walk, STATEgo, STATEgo, STATEgo}},//เดิน 4 walk
  {B00001001, 500, {STATEgo1,STATEgo1,STATEgo1,STATEgo1,STATEgo1,STATEgo1,STATEgo1,STATEgo1}},//เขียวดับเดิน 5 STATEgo
  {B01001001, 500, {STATEgo2,STATEgo2,STATEgo2,STATEgo2,STATEgo2,STATEgo2,STATEgo2,STATEgo2}},//เขียวติดเดิน 6 STATEgo1
  {B00001001, 500, {goldE,goldE,goldE,goldE,goldE,goldE,goldN,goldE}},// 7 STATEgo2
  
  {B00001001, 500, {STATEgo3,STATEgo3,STATEgo3,STATEgo3,STATEgo3,STATEgo3,STATEgo3,STATEgo3}},//เขียวติดเดิน 8 STATEgo5
  {B01001001, 500, {STATEgo4,STATEgo4,STATEgo4,STATEgo4,STATEgo4,STATEgo4,STATEgo4,STATEgo4}},// 9 STATEgo3
  {B00001001, 500, {goldN,goldN,goldN,goldN,goldN,goldN,goldE,goldN}}, // 10 STATEgo4
};

unsigned long S = 0;
void setup() {
  pinMode(LED_W_R, OUTPUT);
  pinMode(LED_W_Y, OUTPUT);
  pinMode(LED_W_G, OUTPUT);
  pinMode(WEST_BUTTON_PIN, INPUT);
  pinMode(LED_S_R, OUTPUT);
  pinMode(LED_S_Y, OUTPUT);
  pinMode(LED_S_G, OUTPUT);
  pinMode(led_goldEalk, OUTPUT);
  pinMode(led_waitEalk, OUTPUT);
  pinMode(SOUTH_BUTTON_PIN, INPUT);
  pinMode(WALK_BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

int input, input1, input2, input3;
long Time = 0;

void loop() {
  digitalWrite(LED_W_R, FSM[S].ST_Out & B00000001);
  digitalWrite(LED_W_Y, FSM[S].ST_Out & B00000010);
  digitalWrite(LED_W_G, FSM[S].ST_Out & B00000100);
  digitalWrite(LED_S_R, FSM[S].ST_Out & B00001000);
  digitalWrite(LED_S_Y, FSM[S].ST_Out & B00010000);
  digitalWrite(LED_S_G, FSM[S].ST_Out & B00100000);
  digitalWrite(led_goldEalk, FSM[S].ST_Out & B01000000);
  digitalWrite(led_waitEalk , FSM[S].ST_Out & B10000000);

  delay(FSM[S].Time);
  input1 = digitalRead(WEST_BUTTON_PIN);
  input2 = digitalRead(SOUTH_BUTTON_PIN);
  input3 = digitalRead(WALK_BUTTON_PIN);

  input = input1 + input2 * 2 +  input3*4;

  S = FSM[S].Next[input];


}
