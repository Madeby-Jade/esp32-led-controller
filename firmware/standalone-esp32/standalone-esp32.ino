// ===================== Modify theses pins according to your ESP32 setup
// ===== PIN DEFINITIONS =====
#define PIN_COLD 7
#define PIN_WARM 10

#define ENC_CLK 3
#define ENC_DT 1
#define ENC_SW 4
// ===== PWM SETTINGS =====
#define PWM_FREQ 5000
#define PWM_RES 8 // 8-bit (0–255)
  
#define CH_COLD 0
#define CH_WARM 1
// ======================================================================
// ===== VARIABLES =====
int brightness = 128; // 0–255
int colorMix = 128; // 0 = warm, 255 = cold

bool adjustColor = false;
int lastCLK;
// ===== SETUP =====
void setup() {
Serial.begin(115200);

// PWM setup
ledcAttach(PIN_COLD, PWM_FREQ, PWM_RES);
ledcAttach(PIN_WARM, PWM_FREQ, PWM_RES);

// Encoder pins
pinMode(ENC_CLK, INPUT_PULLUP);
pinMode(ENC_DT, INPUT_PULLUP);
pinMode(ENC_SW, INPUT_PULLUP);

lastCLK = digitalRead(ENC_CLK);

updateLEDs();
Serial.println("Boot OK");
}
// ===== LOOP =====
void loop() {
readEncoder();
readButton();
}
// ===== FUNCTIONS =====
void readEncoder() {
int currentCLK = digitalRead(ENC_CLK);
if (currentCLK != lastCLK) {
if (digitalRead(ENC_DT) != currentCLK) {
if (adjustColor) {
colorMix = constrain(colorMix + 5, 0, 255);
} else {
brightness = constrain(brightness + 5, 0, 255);
}
} else {
if (adjustColor) {
colorMix = constrain(colorMix - 5, 0, 255);
} else {
brightness = constrain(brightness - 5, 0, 255);
}
}
updateLEDs();
printStatus();
}

lastCLK = currentCLK;
}
void readButton() {
static bool lastState = HIGH;
bool state = digitalRead(ENC_SW);
if (lastState == HIGH && state == LOW) {
adjustColor = !adjustColor;
delay(200); // debounce
}
lastState = state;
}
void updateLEDs() {
int coldPWM = (brightness * colorMix) / 255;
int warmPWM = (brightness * (255 - colorMix)) / 255;
ledcWrite(PIN_COLD, coldPWM);
ledcWrite(PIN_WARM, warmPWM);
}
// For debug purpuses
//void printStatus() {
//Serial.print("Brightness: ");
//Serial.print(brightness);
//Serial.print(" | ColorMix: ");
//Serial.print(colorMix);
//Serial.print(" | Mode: ");
//Serial.println(adjustColor ? "Color Temp" : "Brightness");
//}
