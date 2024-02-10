# RFID Lock Control System

This project demonstrates how to create a simple RFID-based lock control system using Arduino. It utilizes the MFRC522 RFID reader to scan RFID tags and control a lock mechanism. Access is granted or denied based on the RFID tag presented to the reader.

## Hardware Requirements

- Arduino board (Uno, Mega, etc.)
- MFRC522 RFID reader module
- Electronic lock (solenoid lock or similar)
- Jumper wires
- RFID tags compatible with the MFRC522 reader

## Circuit Connections

- **SS_PIN (Slave Select)**: Connect to pin 10 on the Arduino
- **RST_PIN (Reset)**: Connect to pin 9 on the Arduino
- **LOCK_PIN**: Connect to pin 8 on the Arduino (controls the lock mechanism)
- **MFRC522 Module**: Connect to the Arduino's SPI pins (MOSI, MISO, SCK, and GND) as per the SPI standard. The VCC pin should be connected to 3.3V on the Arduino.

## Software Dependencies

- **SPI.h**: Standard SPI library for communication with serial peripherals
- **MFRC522.h**: Library for handling communication with the MFRC522 RFID reader

## Installation

1. Install the Arduino IDE on your computer.
2. Connect your Arduino board to your computer via USB cable.
3. Open the Arduino IDE, and navigate to **Sketch** > **Include Library** > **Manage Libraries...**.
4. Search for and install the `MFRC522` library.
5. Copy the provided code into a new Arduino sketch.
6. Adjust the `authorizedUID` array in the code to match the UID of your RFID tag.
7. Upload the sketch to your Arduino board.

## Usage

1. Power on the Arduino and RFID reader setup.
2. The system will initialize and print "Scan a card" on the serial monitor.
3. Present an RFID tag to the MFRC522 reader.
4. If the UID of the RFID tag matches the authorized UID defined in the code, the lock will unlock for 5 seconds, and "Access Granted" will be displayed on the serial monitor. Otherwise, "Access Denied" will be displayed.

## Customization

- Modify the `authorizedUID` array in the code to change the RFID tag that is authorized to unlock the door.
- Adjust the delay in the `if (accessGranted)` section to change how long the lock remains unlocked.

## Troubleshooting

- Ensure all connections are secure and correctly wired.
- Verify that the RFID tag's UID matches the one specified in the code.
- Check the serial monitor for error messages or debugging information.

## Contributing

Feel free to fork this project and submit pull requests with improvements or report any issues you encounter.
