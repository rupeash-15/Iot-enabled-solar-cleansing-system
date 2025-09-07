\# IoT-Enabled Solar Panel Cleaning System



\## 🌞 Project Overview

This project is an \*\*IoT-enabled solar panel self-cleaning system\*\*.  

It improves solar panel efficiency by removing dust and allows \*\*scheduled cleaning\*\* with minimal water usage.



The system uses:

\- \*\*Arduino + RTC DS1307\*\* → Dust detection (via LDR sensor) and scheduled cleaning.

\- \*\*ESP32 with Bolt IoT Cloud\*\* → Remote monitoring and manual cleaning control.

\- \*\*Relay + Pump/Motor\*\* → For water spraying mechanism.

\- \*\*Minimal Flask Backend\*\* (optional) → For local simulation.



---



\## ⚡ Features

\- Automatic cleaning when dust is detected.

\- Scheduled cleaning (e.g., daily at 10 AM).

\- Remote manual cleaning via \*\*Bolt IoT Cloud dashboard\*\*.

\- Minimal backend (Flask) for testing and interview showcase.

\- Saves water by cleaning only when necessary.



---



\## 🛠️ Hardware Used

\- Arduino UNO

\- ESP32 Module (Bolt IoT Cloud integrated)

\- RTC DS1307 / DS3231

\- LDR Sensor

\- Relay Module

\- Water Pump / Motor

\- Solar Panel (for demo)



---



\## 📂 Project Structure


iot-solar-cleaner/

├── firmware/

│ ├── arduino/solar\_cleaner.ino

│ └── esp32/bolt\_client.ino

├── backend/app.py

├── docs/

│ ├── architecture-diagram.png

│ ├── workflow.png

│ └── project\_report.pdf

├── ui/bolt\_ui.md

├── .gitignore

├── README.md

└── LICENSE



---



\## 🚀 How to Run

1\. \*\*Arduino\*\*: Upload `solar\_cleaner.ino` using Arduino IDE.

2\. \*\*ESP32\*\*: Upload `bolt\_client.ino` using Arduino IDE with ESP32 board support.

3\. \*\*Backend (optional)\*\*:

&nbsp;  ```bash

&nbsp;  python app.py




