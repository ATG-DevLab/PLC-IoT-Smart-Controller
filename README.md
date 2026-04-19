# 🔌 PLC-IoT Smart Controller

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/Platform-Embedded%20Systems-blue)
![Microcontroller](https://img.shields.io/badge/MCU-ATmega328P-orange)
![IoT](https://img.shields.io/badge/IoT-ESP8266-green)
![Project](https://img.shields.io/badge/Project-Smart%20Automation-success)

A **PLC-inspired smart automation controller** that combines **relay-based local control** with **IoT-enabled wireless operation** using **ATmega328P** and **ESP8266**.

This project demonstrates **real-world embedded systems design**, **IoT integration**, and **automation logic** using low-cost hardware.

---

# 📌 Project Overview

The **PLC-IoT Smart Controller** is a **dual-mode automation system** capable of controlling electrical loads using both **physical controls** and **Wi-Fi remote interfaces**.

The system integrates:

• **ATmega328P** for deterministic PLC-style control  
• **ESP8266 (ESP-01)** for IoT connectivity  
• **Multi-mode relay automation** for practical applications  

Designed as a **scalable and reliable automation solution** for home, laboratory, and light-industrial environments.

---

# 🎯 Key Features

- 🔁 **4-Channel Relay Control**
- ⚙️ **PLC-Like Automation Modes**
  - Normal Mode
  - Delay Mode 1
  - Delay Mode 2
- 📶 **IoT Control via Wi-Fi**
- 📱 Web Dashboard / Mobile App Support
- 🔘 Push-Button Mode Selection
- 💡 LED Status Indicators
- 🔐 Electrical Isolation using Relays
- 🧩 Modular and Expandable Design

---

# 🧠 System Architecture

## 🔹 PLC Control Section

- Microcontroller: **ATmega328P**
- Handles relay switching logic
- Executes automation timing modes
- Works independently without internet

## 🔹 IoT Control Section

- Wi-Fi Module: **ESP8266 (ESP-01)**
- Enables remote control via internet
- Communicates with MCU through serial interface
- Demonstrates real-time IoT-to-hardware control

---

# 🖼️ Project Development & Hardware

The following images show the different stages of development and hardware implementation of the PLC IoT Smart Controller project.

1. **Circuit Diagram Planning**  
   Initial hand-drawn circuit diagram showing the architecture of the PLC-style relay control system.

2. **Code Testing on Breadboard**  
   Testing Arduino and ESP communication on a breadboard before final hardware assembly.

3. **ESP-01 Programming using CH340 TTL Converter**  
   Programming the ESP-01 WiFi module using a CH340 USB-TTL converter.

4. **ESP-01 Module**  
   Close view of the ESP-01 WiFi module used for IoT communication.

5. **ESP-01 Side View**  
   Side view showing the pin layout and module structure.

6. **Circuit Making**  
   Initial stage of building the controller circuit on the PCB.

7. **Circuit Compared with Diagram**  
   Comparing the physical circuit with the planned circuit diagram.

8. **Circuit Bottom View**  
   Bottom side of the PCB showing solder connections.

9. **Circuit View**  
   Complete circuit assembled and connected.

10. **Circuit Power Up**  
    First power-on test of the hardware controller.

11. **Project Setup**  
    Complete setup including controller board and connected devices.

12. **Project Testing**  
    Functional testing of relay switching and IoT communication.

13. **Final Smart Controller**  
    Final assembled PLC-IoT Smart Controller ready for operation and demonstration.

---

# 📂 Firmware

The Arduino firmware for the project is available in:

```
Assests/Firmware/PLC_IoT_Controller/PLC_IoT_Controller.ino
```

Steps to upload firmware:

1. Open **Arduino IDE**
2. Navigate to **Assets → Firmware**
3. Open the **.ino file**
4. Select board **Arduino UNO / ATmega328P**
5. Upload the code to the microcontroller

---

# 🔧 Hardware Components

- ATmega328P Microcontroller  
- ESP-01 (ESP8266 Wi-Fi Module)  
- 4-Channel Relay Module (12V / 10A)  
- 7805 Voltage Regulator  
- LEDs & Push Buttons  
- Resistors, Capacitors, Diodes  
- 5V Regulated Power Supply  
- Custom PCB / Veroboard  

---

# 💻 Software & Tools

- Arduino IDE  
- Sinric Pro (IoT Platform)  
- Proteus (Circuit Simulation)  
- Embedded C / Arduino Programming  

---

# ⚙️ Working Principle

• ATmega328P controls relay switching and automation modes  
• Push buttons allow manual mode selection  
• ESP8266 connects to Wi-Fi network  
• Remote commands are received via IoT platform  
• Commands are executed in real time  

The system can operate in **standalone PLC mode** or **IoT-enabled smart automation mode**.

---

# 🏭 Applications

- Home Automation  
- Industrial Control Panels  
- Laboratory Automation  
- Agriculture & Irrigation Systems  
- Smart Energy Management  
- Security & Access Control  

---

# 🎥 Project Demonstration

📺 Full project demonstration available on YouTube:

**Ashish Tech Guruji**

https://www.youtube.com/@AshishTechGuruji

---

# 🚀 Skills Demonstrated

- Embedded Systems Development  
- IoT System Integration  
- Microcontroller Programming  
- Hardware–Software Co-Design  
- Automation Logic Development  
- System Debugging & Testing  

---

# 🔮 Future Improvements

- MQTT Cloud Integration  
- Mobile App Interface  
- Energy Monitoring System  
- OLED / Touch Display Interface  
- Voice Assistant Integration  

---

# 📄 License

This project is licensed under the **MIT License**.
