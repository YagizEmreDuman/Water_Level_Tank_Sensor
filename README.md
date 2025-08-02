# Water Level Monitoring System with ESP32 and Blynk

This project monitors the water level in a tank using an ESP32 microcontroller, an ultrasonic sensor, and the Blynk IoT platform. It measures the distance from the top of the tank to the water surface, calculates the current fill level, and sends the data to your smartphone or computer in real-time.

---

## 🛠️ Hardware Requirements

- ESP32 Development Board
- Waterproof Ultrasonic Sensor (e.g., JSN-SR04T)
- Jumper Wires
- Power Supply (e.g., 5V USB adapter)
- Water Tank

---

## 📲 Software Requirements

- Arduino IDE
- Blynk Library (Install via Library Manager)
- NewPing` Library (Install via Library Manager)

---

## 🔧 Wiring

| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC        | 5V        |
| GND        | GND       |
| TRIG       | GPIO 26   |
| ECHO       | GPIO 25   |

> ⚠️ Make sure your ultrasonic sensor is waterproof if placing it near water.

---

## 🌐 Blynk Setup

1. Go to [Blynk Console](https://blynk.cloud)
2. Create a new template
3. Copy your `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN`
4. Add the following virtual pins:
   - **V0** – Refresh Button
   - **V1** – Water Level Percentage (Gauge)
   - **V2** – Water Height in cm (Label)

---

## 🚀 Upload Instructions

1. Open the `.ino` file in Arduino IDE
2. Select the correct board: **ESP32 Dev Module**
3. Select the correct COM port
4. Paste your Wi-Fi credentials and Blynk tokens in the code
5. Upload the code to your ESP32

---

## 📊 How It Works

- The ultrasonic sensor measures the distance from the sensor to the water surface.
- The water height is calculated by subtracting this distance from the total tank height.
- The percentage fill level is calculated and both values are sent to the Blynk app.

---

## 📷 Example Dashboard

- Gauge (V1): Displays tank fill percentage
- Label (V2): Shows current water height in centimeters
- Button (V0): Manual refresh

---

## 📌 Notes

- You can adjust the `TANK_HEIGHT_CM` constant in the code to match your actual tank size.
- If the sensor returns `0 cm`, the code assumes the tank is empty to avoid false readings.

---

## 🧠 Future Improvements

- Add water level alerts via Blynk notifications
- Log historical data for trend analysis
- Display on physical LCD or OLED

---

## 🧪 License

This project is open-source and free to use for educational and personal purposes.

---
