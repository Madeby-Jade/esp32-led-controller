# ESPHome LED Controller

This version integrates with Home Assistant using ESPHome.

## 🎛️ Controls

- Rotate → Adjust brightness
- Press → Switch mode (brightness / color temperature)
- Long press → Toggle light ON/OFF

## ⚙️ Setup

1. Install ESPHome
2. Copy `led-controller.yaml`
3. Set your Wi-Fi credentials in `secrets.yaml`:

```
wifi_ssid: "your_wifi"
wifi_password: "your_password"
```

4. Upload to ESP32

## 🧠 Features

- Exponential brightness control (feels more natural)
- Smooth color temperature adjustment
- State restore across reboots
