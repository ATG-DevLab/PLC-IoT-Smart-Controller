// By Ashish Prajapati | Founder of Ashish Tech Guruji YouTube Channel 
// Arduino 4 Channel PLC with Manual, Auto (Mode 1), and Sequence (Mode 2) Modes
// Mode 1 ON time = 3s | Mode 2 ON/OFF/Chaser timing = 0.5s

#include <EEPROM.h>

// === Pin Definitions ===
const int inputPins[4]  = {2, 3, 4, 5};     // Manual input buttons
const int outputPins[4] = {6, 7, 8, 9};     // Relay outputs
const int autoModePin   = 12;              // Push button for Auto Mode (Mode 1)
const int seqModePin    = 11;              // Push button for Sequence Mode (Mode 2)
const int modeLedPin    = 13;              // Built-in LED to indicate active mode

// === State Variables ===
bool currentButtonState[4] = {HIGH, HIGH, HIGH, HIGH};
bool lastButtonState[4]    = {HIGH, HIGH, HIGH, HIGH};
bool outputState[4]        = {LOW, LOW, LOW, LOW};

bool autoMode = false;
bool seqMode = false;

// === Debounce Timers ===
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};
const unsigned long debounceDelay = 50;

bool lastAutoModeState = HIGH;
bool currentAutoModeState = HIGH;
unsigned long autoModeLastDebounce = 0;

bool lastSeqModeState = HIGH;
bool currentSeqModeState = HIGH;
unsigned long seqModeLastDebounce = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
    pinMode(outputPins[i], OUTPUT);

    int saved = EEPROM.read(i);
    outputState[i] = (saved == 1) ? HIGH : LOW;
    digitalWrite(outputPins[i], outputState[i]);
  }

  pinMode(autoModePin, INPUT_PULLUP);
  pinMode(seqModePin, INPUT_PULLUP);
  pinMode(modeLedPin, OUTPUT);

  digitalWrite(modeLedPin, LOW);
}

void loop() {
  handleModeToggles();  // Check both mode buttons

  if (seqMode) {
    mode2Sequence();
  } else if (autoMode) {
    mode1Auto();
  } else {
    manualMode();
  }
}

// ====== MODE TOGGLING (Direct Switching Allowed) ======
void handleModeToggles() {
  // --- Auto Mode (Mode 1) ---
  int readingAuto = digitalRead(autoModePin);
  if (readingAuto != lastAutoModeState) {
    autoModeLastDebounce = millis();
  }
  if ((millis() - autoModeLastDebounce) > debounceDelay) {
    if (readingAuto == LOW && currentAutoModeState == HIGH) {
      if (!autoMode) {
        autoMode = true;
        seqMode = false;  // Switch directly from Mode 2 to Mode 1
        Serial.println("Switched to AUTO MODE (Mode 1)");
      } else {
        autoMode = false;
        Serial.println("Returned to MANUAL MODE");
        restoreManualStates();
      }
      updateModeLed();
    }
    currentAutoModeState = readingAuto;
  }
  lastAutoModeState = readingAuto;

  // --- Sequence Mode (Mode 2) ---
  int readingSeq = digitalRead(seqModePin);
  if (readingSeq != lastSeqModeState) {
    seqModeLastDebounce = millis();
  }
  if ((millis() - seqModeLastDebounce) > debounceDelay) {
    if (readingSeq == LOW && currentSeqModeState == HIGH) {
      if (!seqMode) {
        seqMode = true;
        autoMode = false;  // Switch directly from Mode 1 to Mode 2
        Serial.println("Switched to SEQUENCE MODE (Mode 2)");
      } else {
        seqMode = false;
        Serial.println("Returned to MANUAL MODE");
        restoreManualStates();
      }
      updateModeLed();
    }
    currentSeqModeState = readingSeq;
  }
  lastSeqModeState = readingSeq;
}

// ====== UPDATE MODE LED ======
void updateModeLed() {
  digitalWrite(modeLedPin, (autoMode || seqMode) ? HIGH : LOW);
}

// ====== MANUAL MODE ======
void manualMode() {
  for (int i = 0; i < 4; i++) {
    int reading = digitalRead(inputPins[i]);
    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }
    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (reading == LOW && currentButtonState[i] == HIGH) {
        outputState[i] = !outputState[i];
        digitalWrite(outputPins[i], outputState[i]);
        EEPROM.write(i, outputState[i] == HIGH ? 1 : 0);
        Serial.print("Manual Toggle - Output ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(outputState[i] ? "ON" : "OFF");
      }
      currentButtonState[i] = reading;
    }
    lastButtonState[i] = reading;
  }
}

// ====== AUTO MODE (MODE 1) ======
void mode1Auto() {
  Serial.println("Mode 1: All outputs ON for 3 seconds");
  for (int i = 0; i < 4; i++) digitalWrite(outputPins[i], HIGH);
  if (!delayWithModeCheck(3000)) return;

  for (int i = 0; i < 4; i++) {
    Serial.print("Mode 1: Turning OFF Output ");
    Serial.print(i + 1);
    Serial.println(" for 2 seconds");
    digitalWrite(outputPins[i], LOW);
    if (!delayWithModeCheck(2000)) return;
    digitalWrite(outputPins[i], HIGH);
    if (!autoMode || seqMode) return;
  }
}

// ====== SEQUENCE MODE (MODE 2) ======
void mode2Sequence() {
  const unsigned long seqDelay = 500; // 0.5 seconds

  Serial.println("Mode 2: Turning ON outputs one by one");
  for (int i = 0; i < 4; i++) {
    digitalWrite(outputPins[i], HIGH);
    if (!delayWithModeCheck(seqDelay)) return;
  }

  Serial.println("Mode 2: Turning OFF outputs one by one");
  for (int i = 0; i < 4; i++) {
    digitalWrite(outputPins[i], LOW);
    if (!delayWithModeCheck(seqDelay)) return;
  }

  Serial.println("Mode 2: LED chaser pattern");
  for (int i = 0; i < 4; i++) {
    digitalWrite(outputPins[i], HIGH);
    if (!delayWithModeCheck(seqDelay)) return;
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(outputPins[i], LOW);
    if (!delayWithModeCheck(seqDelay)) return;
  }
}

// ====== DELAY WITH MODE CHANGE CHECK ======
bool delayWithModeCheck(unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    handleModeToggles();  // Check if user changed mode
    
    if ((!seqMode && !autoMode) || (autoMode && seqMode)) return false;
  }
  return true;
}

// ====== RESTORE MANUAL STATE FROM EEPROM ======
void restoreManualStates() {
  for (int i = 0; i < 4; i++) {
    outputState[i] = EEPROM.read(i) == 1 ? HIGH : LOW;
    digitalWrite(outputPins[i], outputState[i]);
  }
}
