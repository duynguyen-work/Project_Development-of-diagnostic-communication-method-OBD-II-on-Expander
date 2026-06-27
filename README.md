# Development of Diagnostic Communication Method through OBD-II Port on Mitsubishi Xpander 2019 and IoT-Based Vehicle Diagnostic Monitoring

An embedded IoT system for collecting real-time vehicle diagnostic data through the **OBD-II** interface and transmitting the information to a cloud platform for remote monitoring and visualization.

The project develops a diagnostic communication method for the **Mitsubishi Xpander 2019**, integrating an **Arduino MKR1000**, an **ELM327-compatible OBD-II interface**, and a cloud-based IoT dashboard to monitor vehicle operating parameters in real time.

---

# 🌟 Project Highlights

The project combines automotive diagnostics and Internet of Things (IoT) technologies to build a low-cost vehicle monitoring system.

### Key Features

* Real-time OBD-II data acquisition
* Wi-Fi communication using Arduino MKR1000
* Cloud-based data transmission and storage
* IoT dashboard for live vehicle monitoring
* Modular software architecture
* Low-cost implementation suitable for academic research

---

# 🚗 System Overview

The proposed system consists of four major modules:

```text
Vehicle ECU
      │
      ▼
OBD-II Port
      │
      ▼
OBD-II Interface (ELM327)
      │
      ▼
Arduino MKR1000
      │
      ▼
Wi-Fi
      │
      ▼
Cloud Server
      │
      ▼
Web Dashboard
```

Vehicle diagnostic information is collected through the OBD-II port, processed by the Arduino MKR1000, transmitted over Wi-Fi, stored in the cloud, and displayed through a user-friendly IoT dashboard.

---

# 🎯 Objectives

The primary objective is to develop a diagnostic communication method through the OBD-II interface on the **Mitsubishi Xpander 2019** and build an IoT platform capable of displaying vehicle diagnostic data remotely.

The project includes:

* Reading diagnostic parameters from the vehicle ECU
* Processing OBD-II signals
* Wireless data transmission
* Cloud data storage
* Web-based visualization

---

# 📊 Supported Vehicle Parameters

The implemented system can acquire various real-time vehicle parameters, including:

* Engine Speed (RPM)
* Vehicle Speed
* Battery Voltage
* Engine Coolant Temperature
* Intake Air Temperature
* Throttle Position
* Accelerator Pedal Position
* Oxygen Sensor Signals

The available parameters may vary depending on the supported PIDs of the target vehicle.

---

# ⚙ Hardware Components

* Mitsubishi Xpander 2019
* Arduino MKR1000
* OBD-II Interface (ELM327 Compatible)
* Wi-Fi Network
* Personal Computer
* Cloud Platform

---

# 💻 Software Stack

* Arduino IDE
* C/C++
* Arduino MKR1000 Libraries
* IoT Cloud Platform
* UART Communication
* OBD-II Protocol

---

# 📂 Project Structure

```text
├── Reference/
│   ├── Arduino MKR1000 Documentation
│   ├── ATSAMW25 Datasheets
│   ├── MKR1000 SAMD21 Documentation
│   ├── IoT Arduino Cookbook
│   └── OBD-II UART Library
│
├── report/
│   ├── Project Proposal
│   ├── Development Plan
│   ├── Final Report
│   ├── Presentation Slides
│   └── Project Documentation
│
├── source/
│   ├── IOT4CAR.ino             # Main Arduino application
│   ├── CloudClient.cpp         # Cloud communication
│   ├── CloudClient.h
│   ├── OBDManager.cpp          # OBD-II communication module
│   ├── OBDManager.h
│   ├── WifiManager.cpp         # Wi-Fi management
│   └── WifiManager.h
│
├── README.md
└── .gitignore
```

---

# 🧩 Software Architecture

## OBD Manager

Responsible for

* ECU communication
* PID requests
* OBD-II response decoding
* Signal processing

---

## WiFi Manager

Handles

* Wi-Fi connection
* Network reconnection
* Communication management

---

## Cloud Client

Responsible for

* Uploading sensor data
* Cloud authentication
* Data synchronization
* Remote monitoring

---

## Main Application

Coordinates

* OBD-II polling
* Data processing
* Cloud transmission
* Timing control

---

# 🚀 Getting Started

## Hardware Setup

1. Connect the OBD-II adapter to the vehicle diagnostic port.
2. Connect the adapter to the Arduino MKR1000.
3. Configure the Wi-Fi credentials.
4. Upload the firmware using Arduino IDE.

---

## Software Installation

Clone the repository

```bash
git clone <repository_url>
```

Install required Arduino libraries and open

```text
source/IOT4CAR.ino
```

Compile and upload the project to the Arduino MKR1000.

---

# 📈 Experimental Evaluation

The developed prototype was evaluated on a **2019 Mitsubishi Xpander** under real driving conditions.

The evaluation focused on:

* OBD-II communication reliability
* Data acquisition accuracy
* Cloud transmission stability
* Dashboard visualization performance

The results demonstrate that the proposed system can reliably acquire and display real-time vehicle diagnostic information with acceptable latency for IoT monitoring applications.

---

# 🔮 Future Improvements

* [ ] Simultaneous multi-PID processing using pointer-based programming
* [ ] Migration to STM32F407 Discovery platform
* [ ] MATLAB GUI integration
* [ ] Mobile application development
* [ ] GPS tracking integration
* [ ] Vehicle fault code (DTC) diagnosis
* [ ] CAN Bus monitoring
* [ ] MQTT communication
* [ ] OTA firmware update

---

# 📚 References

1. Bosch. *Automotive Electrics and Electronics*.

2. Konrad Reif. *Automotive Mechatronics*. Bosch Professional Automotive Information.

3. Đỗ Văn Dũng. *Electrical Systems and Engine Control*.

4. SAE International. *SAE J1979 - E/E Diagnostic Test Modes*.

5. ISO 15031. *Road Vehicles — Communication Between Vehicle and External Equipment for Emissions-Related Diagnostics*.

---

# 📄 License

This project was developed for academic research and educational purposes. It demonstrates the implementation of an embedded IoT system for vehicle diagnostics using the OBD-II communication protocol and cloud-based data visualization.
