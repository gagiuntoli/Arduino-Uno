
#define PIN_DATA          8
#define PIN_LATCH_CLOCK   9
#define PIN_SHIFT_CLOCK   10
#define PIN_D1            7
#define PIN_D2            6
#define PIN_D3            5
#define PIN_D4            4
#define DELAY_SHIFT_CLOCK 0.001
#define DELAY_MULTIPLEX   5

void make_pulse_74HC595()
{
  digitalWrite(PIN_SHIFT_CLOCK, HIGH);
  delay(DELAY_SHIFT_CLOCK);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  delay(DELAY_SHIFT_CLOCK);
}

void send_num_serial_74HC595(int num, bool point)
{
  digitalWrite(PIN_LATCH_CLOCK, LOW);
  byte num_binary[10] = {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11110110};

  for (int i = 0; i < 8; i++) {
    if (point) bitWrite(num_binary[num], 0, 1);
    digitalWrite(PIN_DATA, bitRead(num_binary[num], i) ? HIGH : LOW);
    make_pulse_74HC595();
  }
  digitalWrite(PIN_LATCH_CLOCK, HIGH);
}

void multiplex_num(int num[4], int point_pos)
{
  int displays[4] = {PIN_D1, PIN_D2, PIN_D3, PIN_D4};
  for (int i = 0; i < 4; i++) {
    if (num[i] < 0) num[i] = 0;
    if (num[i] > 9) num[i] = 9;
  }
  for (int i = 0; i < 4; i++) {
    send_num_serial_74HC595(num[i], false);
    digitalWrite(displays[i], LOW);
    delay(DELAY_MULTIPLEX);
    digitalWrite(displays[i], HIGH);
  }
}

void setup()
{
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_LATCH_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_LATCH_CLOCK, LOW);
  digitalWrite(PIN_DATA, LOW);
  digitalWrite(PIN_D1, HIGH);
  digitalWrite(PIN_D2, HIGH);
  digitalWrite(PIN_D3, HIGH);
  digitalWrite(PIN_D4, HIGH);
}

void loop()
{
  int num[4] = {1, 9, 8, 4};
  multiplex_num(num, 1);
}
