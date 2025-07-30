# Density-Based Traffic Control System 🚦

There some projects which really get you excited, this is one such project which got me. This project is a prototype of a **smart traffic control system** that dynamically adjusts signal timing based on real-time traffic density using **IR sensors**. The system is powered by an **ATmega8 microcontroller**, making it low-cost, efficient, and suitable for embedded applications.

---

## 🔧 Hardware Components

- **ATmega8 Microcontroller**
- **IR Sensors** × 4 (for vehicle detection on each lane)
- **LEDs** × 12  
  - 4 × Red  
  - 4 × Green  
  - 4 × Yellow
- **12V Battery or Adapter** (for power supply)
- **Serial Cable** (for programming/debugging)
- **Connecting Wires**

---

## ⚙️ Features

- Real-time traffic density detection using IR sensors  
- Adaptive signal timing based on sensor input  
- Microcontroller-based control using ATmega8  
- LED signals for Red, Yellow, and Green lights per lane  
- Simple and power-efficient design  

---

## 🔌 Circuit Overview

- Each IR sensor is placed at a specific distance on all four roads to detect vehicle presence.
- Based on the number of sensors triggered per road, traffic density is estimated.
- The ATmega8 processes sensor data and assigns longer green signal duration to more congested lanes.
- LEDs simulate traffic signals.
- Power is supplied via a 12V battery or adapter.

---

## 🚀 Getting Started

### 1. **Wiring and Setup**
- Connect IR sensors to digital input pins of ATmega8.
- Connect LEDs to output pins via resistors.
- Use a 12V adapter/battery to power the board and components.
- Upload the code to ATmega8 using a serial cable and compatible ISP programmer.

### 2. **Dependencies**
- AVR-GCC toolchain (for compiling C code)
- AVRDUDE (for uploading to ATmega8)
- Proteus or other simulation software (optional for testing)

---

## 🧠 Working Principle

Each IR sensor detects vehicle presence. The ATmega8 reads the input and calculates traffic density per lane:
- If a lane has higher density (more sensors triggered), it gets a longer green signal time.
- The other lanes are managed in sequence with shorter durations based on density.
- LED signals are controlled accordingly for red/yellow/green transitions.

---



