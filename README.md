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

### 01 – Circuit Diagram Planning
![01](Assets/Project-images/01_circuit_diagram_planing_stage.png)

### 02 – Code Testing on Breadboard
![02](Assets/Project-images/02_code_testing_on_breadboard.png)

### 03 – ESP-01 Programming using CH340 TTL Converter
![03](Assets/Project-images/03_esp-01_programming_using_ch340_ttl_converter.png)

### 04 – ESP-01 Module
![04](Assets/Project-images/04_esp-01_module.png)

### 05 – ESP-01 Side View
![05](Assets/Project-images/05_esp-01_side_view.png)

### 06 – Circuit Making
![06](Assets/Project-images/06_circuit_making.png)

### 07 – Circuit Compared with Diagram
![07](Assets/Project-images/07_circuit_compare_with_diagram.png)

### 08 – Circuit Bottom View
![08](Assets/Project-images/08_circuit_bottom_view.png)

### 09 – Circuit View
![09](Assets/Project-images/09_circuit_view.png)

### 10 – Circuit Power Up
![10](Assets/Project-images/10_circuit_powerup.png)

### 11 – Project Setup
![11](Assets/Project-images/11_project_setup.png)

### 12 – Project Testing
![12](Assets/Project-images/12_project_testing.png)

### 13 – Final Smart Controller
![13](Assets/Project-images/13_smart_controller_youtube_video_thumbnail.png)

---

# 📂 Firmware

The Arduino firmware for the project is available in:

```
Assets/Firmware/
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
