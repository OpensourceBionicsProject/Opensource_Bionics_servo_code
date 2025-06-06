# OpenSource Bionics – Servo Control Code

This repository contains Arduino code examples for controlling a prosthetic hand developed as part of the **OpenSource Bionics** project.

## Overview

Three different control methods are included:

### 1. Potentiometer Control
Uses a standard analog potentiometer to control the hand's position smoothly. Turning the potentiometer adjusts the servo angle, simulating finger movement.

### 2. Button Control
Simplified digital control using a button. One press closes the hand, and the next press opens it again. Useful for basic functionality tests or demonstrations.

### 3. Muscle Sensor Control (AD8232)
This version utilizes the **AD8232** muscle activity sensor (EMG sensor). The sensor detects muscle contractions from the user’s forearm and translates them into servo movements, mimicking natural hand motion.

## Requirements

- Arduino Uno or compatible board  
- Servo motor (e.g., TowerPro SG5010)  
- Potentiometer (10kΩ recommended)  
- Pushbutton  
- AD8232 muscle sensor  
- Jumper wires, breadboard, and power supply

## How to Use

1. Clone or download this repository.
2. Open the desired `.ino` file in [Arduino IDE](https://www.arduino.cc/en/software).
3. Connect the components according to the schematic comments in the code.
4. Upload to your Arduino board.
5. Power up and test the control method.

## License

This project is licensed under the MIT License. You are free to use, modify, and share the code.

---

### Part of the [OpenSource Bionics](https://github.com/yourprojectlink) initiative.
