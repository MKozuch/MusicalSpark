#define T0Prescaler 256

int figurePrescaler(int freq){
  return 16500000L / T0Prescaler / freq;
}

void playNote(int freq, int len){
  OCR0A = figurePrescaler(freq);
  delay(len);
  playNoNote(5);
}
void playNoNote(int len){
  OCR0A = 0;
  if(len > 0)
    delay(len);
}
int noteToFreq(char note){
  if(note == 'a') return 440;
  if(note == ' ') return 466;
  if(note == 'b') return 494;
  if(note == 'c') return 523;
  if(note == ' ') return 554;
  if(note == 'd') return 587;
  if(note == ' ') return 622;
  if(note == 'e') return 659;
  if(note == 'f') return 698;
  if(note == ' ') return 740;
  if(note == 'g') return 784;
  if(note == ' ') return 831;
  if(note == 'A') return 880;
}
  // const int baseA = 440;
  // const unsigned char diff = abs(note - 'a');
  // return baseA * 18 * diff / 17;

void playNote(char freq, int len){
  playNote(noteToFreq(freq), len);
}

void setup() {
  // Set CTC mode
  // Toggle OC0A/OC0B on Compare Match
  // Prescaler to 256
  TCCR0A = 0b01000010; 
  TCCR0B = 0b00000100; 
  OCR0A = 0x0F;

  DDRB |= (1<<PB0);

  playNote(440, 10);
  playNote(466, 10);
  playNote(494, 10);
  playNote(523, 10);
  playNote(554, 10);
  playNote(587, 10);
  playNote(659, 10);
  playNote(698, 10);
  playNote(740, 10);
  playNote(784, 10);
  playNote(831, 10);
  playNote(880, 10);
}

void loop() {
  playNote('c', 500);
  playNote('c', 500);
  playNote('g', 500);
  playNote('g', 500);
  playNote('A', 500);
  playNote('A', 500);
  playNote('g', 1000);
  
  playNote('f', 500);
  playNote('f', 500);
  playNote('e', 500);
  playNote('e', 500);
  playNote('d', 500);
  playNote('d', 500);
  playNote('c', 1000);

  playNote('g', 500);
  playNote('g', 500);
  playNote('f', 500);
  playNote('f', 500);
  playNote('e', 500);
  playNote('e', 500);
  playNote('d', 1000);

  playNote('g', 500);
  playNote('g', 500);
  playNote('f', 500);
  playNote('f', 500);
  playNote('e', 500);
  playNote('e', 500);
  playNote('d', 1000);


  playNote('c', 500);
  playNote('c', 500);
  playNote('g', 500);
  playNote('g', 500);
  playNote('A', 500);
  playNote('A', 500);
  playNote('g', 1000);
  
  playNote('f', 500);
  playNote('f', 500);
  playNote('e', 500);
  playNote('e', 500);
  playNote('d', 500);
  playNote('d', 500);
  playNote('c', 1000);

  /*
    static unsigned char i = 0;
    static float f = 0;
    i++;
    f = float(i)/255 * (2*PI);
    OCR0A = ((cos(f)/2) + 0.5)  * 255;
    delay(10);
  */
}
