\# Bolt IoT Cloud UI Setup for Solar Cleaner



\## Steps to Configure Dashboard

1\. Log in to \[Bolt Cloud](https://cloud.boltiot.com/).

2\. Add your ESP32 device using \*\*Device ID\*\*.

3\. Go to \*\*Products → Create Product\*\*:

&nbsp;  - Name: Solar Cleaner Control

&nbsp;  - Type: Output Device (Digital)

&nbsp;  - Pin: 0 (example)



4\. Link product to your device.

5\. Create a dashboard UI:

&nbsp;  - Add \*\*Button\*\* → to trigger pump ON/OFF.

&nbsp;  - Add \*\*Graph\*\* → to monitor LDR values (optional).



6\. Save changes and use the button to manually start cleaning.



---



\## Example Workflow

\- User presses \*\*CLEAN button\*\* on dashboard →  

\- Bolt Cloud sends command to ESP32 →  

\- ESP32 activates relay →  

\- Pump runs for 5 seconds →  

\- Cleaning complete.



