#define T0Prescaler 256
#include "notes.h"
#include "scaleGenerator.h"

// constexpr functions must be prototyped
constexpr unsigned int figurePrescaler(int freq);

constexpr unsigned int figurePrescaler(int freq) {
  return F_CPU / T0Prescaler / freq;
}
void playFreq(int freq){
    OCR0A = figurePrescaler(freq);
}
void playNote(Note::NoteName note, int len) {
  const auto freq = Note::noteValues[note];
  playFreq(freq);
  delay(len);
  playNoNote(5);
}
void playNoNote(int len) {
  OCR0A = 0;
  if (len > 0)
    delay(len);
}

#include "kurkiTrzy.h"

void setup() {
  // Set CTC mode
  // Toggle OC0A/OC0B on Compare Match
  // Prescaler to 256
  TCCR0A = 0b01000010;
  TCCR0B = 0b00000100;
  OCR0A = 0x0F;

  DDRB |= (1 << PB0);

using namespace Note;
  playNote(C,  50);
  playNote(Cs, 50);
  playNote(D,  50);
  playNote(Ds, 50);
  playNote(E,  50);
  playNote(F,  50);
  playNote(Fs, 50);
  playNote(G,  50);
  playNote(Gs, 50);
  playNote(A,  50);
  playNote(As, 50);
  playNote(B,  50);
}

void loop() {
  using namespace Note;

//for(char mode=0; mode<7; ++mode)
//  for(char i = 0; i < 8; ++i)
//    playNote(ScaleGenerator::generateStep(C5, ScaleGenerator::Mode(mode), i), 500);
for(char tonic=C5; tonic<C6; ++tonic)
  for(char i = 0; i < 8; ++i)
    playNote(ScaleGenerator::generateStep(NoteName(tonic), ScaleGenerator::Minor, i), 500);
}
