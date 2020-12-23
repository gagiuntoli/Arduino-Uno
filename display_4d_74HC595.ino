
#define PIN_DATA          8
#define PIN_LATCH_CLOCK   9
#define PIN_SHIFT_CLOCK   10
#define DELAY_SHIFT_CLOCK 1

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
    digitalWrite(PIN_DATA, bitRead(num_binary[num], i) ? HIGH : LOW);
    make_pulse_74HC595();
  }
  digitalWrite(PIN_LATCH_CLOCK, HIGH);
}

void setup() {

  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_LATCH_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_LATCH_CLOCK, LOW);
  digitalWrite(PIN_DATA, LOW);
}

void loop() {
  
  send_num_serial_74HC595(9, true);

}
