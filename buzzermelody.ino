int buzzer = 4;

// Notes (Hz)
#define C4  262
#define Db4 277
#define D4  294
#define Eb4 311
#define E4  330
#define F4  349
#define Gb4 370
#define G4  392
#define Ab4 415
#define A4  440
#define Bb4 466
#define B4  494
#define C5  523

// Melody (main notes)
int melody[] = {
  Db4, Eb4, F4, Eb4, Db4, Bb4, Db4, // measure 1
  Db4, Eb4, F4, Eb4, Db4, Bb4, Db4, // measure 2
  // ... continue for full melody
};

// Durations (ms)
int durations[] = {
  150, 150, 300, 150, 150, 300, 300, // measure 1
  150, 150, 300, 150, 150, 300, 300, // measure 2
  // ... continue for full melody
};

int length = sizeof(melody) / sizeof(melody[0]);

void setup() {
}

void loop() {
  for (int i = 0; i < length; i++) {
    tone(buzzer, melody[i], durations[i]);
    delay(durations[i] + 50);
  }
  delay(500); // pause before looping
}
