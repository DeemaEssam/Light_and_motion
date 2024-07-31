# Sensor-Based LED Control System

## Overview

This task involves using two sensors—a PIR sensor and a light sensor—to control an LED based on specific conditions. The system performs the following actions:

- **Movement without Light**: Turns on the LED.
- **Movement with Light**: Turns off the LED.
- **No Movement with Light**: Turns off the LED.
- **No Movement without Light**: Turns off the LED.

All sensor data and LED states are saved in a database.

## Components

- **PIR Sensor**: Detects motion based on infrared radiation changes.
- **Light Sensor**: Detects the presence or absence of light.
- **Relay**: Controls the power to the LED.
- **LED**: Indicates the state based on sensor input.

## System Requirements

- **Microcontroller/Platform**: ESP32 (or similar)
- **Sensors**: PIR sensor (for movement detection), Light sensor (e.g., LDR)
- **Actuator**: Relay module
- **Database**: MySQL (or similar)

## Setup

1. **Hardware Connections**:
    - Connect the PIR sensor to the ESP32.
    - Connect the light sensor to the ESP32.
    - Connect the relay module to the ESP32 to control the LED.
    - Connect the LED to the relay module.

2. **Software Setup**:
    - Install necessary libraries for sensor and relay control.
    - Configure the microcontroller code to read from the PIR sensor and light sensor, and control the relay based on the conditions outlined.

3. **Database Configuration**:
    - Set up a MySQL database to store sensor readings and LED states.
    - Ensure that your microcontroller is connected to the database for logging data.

## Code

Here's a brief overview of the code logic:

1. Read the light sensor value.
2. Read the PIR sensor value to detect movement.
3. Determine the LED state based on the light sensor value and PIR sensor data.
4. Control the relay to turn the LED on or off accordingly.
5. Save the sensor readings and LED state to the database.

   
## Database Schema

The database should have a table to store the sensor data and LED state:

```sql
CREATE TABLE `sensor_data` (
  `id` int(11) NOT NULL,
  `light_level` int(11) DEFAULT NULL,
  `motion_detected` tinyint(1) DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp()
)
```


## Output

 <img src="https://github.com/user-attachments/assets/1e335f0c-bc89-428e-b8c8-efb1b7347205" width="580" height="290">


 
![ضوء بدون حركة2](https://github.com/user-attachments/assets/1e335f0c-bc89-428e-b8c8-efb1b7347205)
