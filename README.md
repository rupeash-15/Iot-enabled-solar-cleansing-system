🌞 IoT-Enabled Solar Panel Cleaning System
📖 About the Project

An IoT-enabled self-cleaning system for solar panels that improves efficiency by automatically removing dust, scheduling cleanings, and enabling remote monitoring with minimal water usage.

🔧 System Components

Arduino + RTC DS1307 → Dust detection (LDR) & scheduled cleaning

ESP32 + Bolt IoT Cloud → Remote monitoring & manual cleaning

Relay + Pump/Motor → Automated water spray mechanism

Flask Backend (Optional) → Local simulation & demo

⚡ Features

🧹 Automatic cleaning when dust is detected

⏰ Scheduled cleaning (e.g., daily at 10 AM)

🌐 Remote manual cleaning via Bolt IoT Cloud

💧 Water-efficient — cleans only when necessary

🖥️ Optional Flask backend for testing/interviews


| Component               | Purpose / Function                                                                  |
| ----------------------- | ----------------------------------------------------------------------------------- |
| **Arduino UNO**         | Controls the LDR sensor, RTC, and relay module for cleaning automation.             |
| **ESP32**               | Connects to **Bolt IoT Cloud** for remote monitoring and manual control.            |
| **RTC DS1307 / DS3231** | Provides real-time clock for scheduled cleaning (e.g., daily at 10 AM).             |
| **LDR Sensor**          | Detects dust levels by measuring light intensity on the solar panel.                |
| **Relay Module**        | Acts as a switch to control the water pump/motor based on Arduino’s commands.       |
| **Water Pump / Motor**  | Sprays water to clean the solar panel surface.                                      |
| **Solar Panel**         | Used in the demo setup; the target device being cleaned for efficiency improvement. |


iot-solar-cleaner/
│
├── firmware/
│   ├── arduino/solar_cleaner.ino      # Arduino sketch
│   └── esp32/bolt_client.ino          # ESP32 firmware
│
├── backend/app.py                     # Flask backend (optional)
│
├── docs/
│   ├── architecture-diagram.png
│   ├── workflow.png
│   └── project_report.pdf
│
├── ui/bolt_ui.md                      # Bolt IoT UI setup guide
├── .gitignore
├── README.md
└── LICENSE



🚀 How to Run
1️⃣ Arduino Firmware

Upload solar_cleaner.ino to Arduino UNO using Arduino IDE.
Handles dust detection (LDR) & scheduled cleaning (RTC).

2️⃣ ESP32 Firmware

Upload bolt_client.ino to ESP32 with Bolt IoT integration.
Enables remote control & monitoring.



