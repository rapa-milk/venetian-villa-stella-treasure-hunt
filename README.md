# Treasure Hunt with Video Guidance and Code Inputing

This project is intended to be used with RFID sensor triggering the playback of specific videos using Open Frameworks, in the current prototype iteration it uses codes laser cuttend on the findable objects. Each RFID tag / code corresponds to a unique video, creating an interactive and automated game.

## Features

- **RFID Integration**: Utilizes an RFID sensor to read tags connected to an arduino.
- **Video Playback**: Automatically opens and plays a designated video based on the RFID tag detected.

## Requirements

- **Hardware**:
  - Physical objects with codes printed on them
  - **Optional**
    - RFID sensor and compatible RFID tags
    - Arduino nano.
- **Software**:
  - Open Frameworks (version 0.12.0)
  - **Optional**
    - Any necessary drivers or libraries for your RFID sensor

## Installation

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/rfid-video-player.git
    cd rfid-video-player
    ```

2. **Set Up Open Frameworks**:
   - Follow the [Open Frameworks setup guide](https://openframeworks.cc/download/) for your operating system.

3. **Install Dependencies**:
   - Ensure you have all necessary dependencies installed for your RFID sensor.
   - Install any additional libraries required by your project.

4. **Build the Project**:
   - Open the project in your Open Frameworks IDE or your preferred development environment.
   - Compile and build the project.

## Usage

1. **[Optional] Connect the RFID Sensor**:
   - Connect your RFID sensor to the computer trough an arduino with the appropriate code in the arduino directory.

2. **Run the Application**:
   - Launch the compiled application.
   - Follow the instructions on screen.
     - Scan an RFID tag or input the code.
     - The application will detect the RFID tag/code and play the corresponding video, if the tag/code is not the subsequent it will allert of the error and wait for the next attempt.


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
