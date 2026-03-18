# Standalone ESP32 LED Controller

This version runs fully offline using a rotary encoder.

## 🎛️ Controls

- Rotate → Adjust brightness
- Press button → Toggle mode
  - Brightness mode
  - Color temperature mode

## ⚙️ Configuration

- Set GPIO pins
- Adjust PWM settings if needed

## ⬆️ Upload

1. Open `standalone-esp32.ino` in Arduino IDE
2. Select your ESP32 board
3. Upload

## 🧠 How it works

- Brightness: 0–255
- ColorMix:
  - 0 → fully warm
  - 255 → fully cold

PWM output is split between warm and cold LEDs.
