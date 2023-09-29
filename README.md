# IEEE Embedded Systems Workshop: Microcontroller Architecture and Interfacing with ARM Cortex
## Workshop content:
1) C-Language Basics.
2) Advanced C Programming: pointers,macros,processor architecture and memory types.
3) ARM Architecture.
4) Microcontroller Peripherals.
5) Real-Time Scheduling.
6) Communucation interfaces: UART,SPI...etc.
7) DMA (Direct memory access).
8) Hands-On Practice.

## Mini Project Proposal: Simulated Traffic Management System

### Mini Project Overview
We propose the development of a Simulated Traffic Management System that efficiently controls traffic lights based on pedestrian crosswalk requests. This system will utilize an STM32F103C8 microcontroller and various components, simulated within the Proteus environment, to manage traffic lights for both vehicles and pedestrians. Additionally, we will implement this system using FreeRTOS to ensure real-time operation and efficient multitasking.

### Mini Project Objectives
#### Mini Project Primary Objectives
1) Control traffic lights for cars and pedestrians within the Proteus simulation environment.
2) Efficiently respond to pedestrian crosswalk requests.
3) Implement error handling and reporting.
4)Utilize FreeRTOS for real-time operation and multitasking.

### Hardware and Software Requirements
#### Hardware Requirements (Simulated within Proteus)
* STM32F103C8 microcontroller simulation.
* Virtual push button for pedestrian requests.
* Virtual LEDs for traffic lights - Red, Yellow, and Green for cars and pedestrians.

#### Software Requirements
* In normal mode (simulation):
  * Traffic lights for cars will cycle every five seconds: Green, Yellow, Red, Yellow, Green.
  * The Yellow LED will blink for five seconds before transitioning to Green or Red.
* In pedestrian mode (simulation):
  * Transition to pedestrian mode when the virtual pedestrian button is pressed.
  * Pedestrians can cross the street when the pedestrian's Green LED is on.
  * Pedestrians must wait when cars have the right of way.
  * Specific sequences for pedestrian crosswalk requests.
  
### System Design
  * Define system layers.
  * Define system drivers.
  * Place each driver into the appropriate layer following SOLID principles.
  * Define APIs for each driver with documentation.
  * Define new data types for drivers.
  * Define error handling and reporting mechanisms.
  
### Development Environment
  * Configure Proteus simulation environment.
  * Implement layered architecture in the Proteus project structure.
  * Prepare all files for development with header file guards.
  * Write typedefs and function prototypes.
  * Include lower layer drivers in upper layer/calling drivers' header files.
  
### Implementation
  * Write skeleton code for each function with comments.
  * Convert comments into appropriate code.
  * Ensure functions return error states.
  
### Testing
  * Develop test modules for each driver.
  * Implement and validate driver output within the Proteus simulation.
  
### System Flow
  * Define the system flow based on requirements.
  * Implement the system flow in the “APP_start” function.
  
### User Stories and Testing
  1) User Story 1: As a pedestrian, when I make a short press on the crosswalk button while the cars' green light is on and the pedestrian red light is on, I will wait for the yellow lights to blink for five seconds, then the cars' red light is on, and the pedestrian green light is on for five seconds, so that I can cross the street.
  
  2) User Story 2: As a pedestrian, when I make a short press on the crosswalk button while the cars' yellow light is blinking and the pedestrian red light is on, I will wait for all yellow lights to blink for five seconds, then the cars' red light is on, and the pedestrian green light is on for five seconds, so that I can cross the street.
  
  3) User Story 3: As a pedestrian, when I make a short press on the crosswalk button while the cars' red light is on and the pedestrian green light is on, I expect nothing to be done.
  
  4) User Story 4: As a pedestrian, when I make a long press on the crosswalk button, I expect nothing to be done.
  
  5) User Story 5: As a pedestrian, when I make a double press on the crosswalk button, I expect that the first press will do the action, and nothing will be done after the second press.

### Mini Project Conclusion
  This mini project aims to create an efficient Simulated Traffic Management System that handles both vehicle traffic and pedestrian crosswalk requests within 
  the Proteus simulation environment. By implementing this system with FreeRTOS, we ensure real-time operation and responsiveness. The final product will 
  contribute to safer and more organized traffic management, even in a virtual setting.

## Final Project Proposal: Autonomous Obstacle-Avoidance and Line Tracking Car with FreeRTOS

### Final Project Overview
We propose the development of an autonomous car capable of detecting obstacles and tracking lines using ultrasonic sensors and infrared sensors and managing tasks efficiently with FreeRTOS. The car will use a combination of components, including ultrasonic sensors, L293D motor driver, LCD display, infrared sensors, and servo motor, to create a functional and efficient obstacle-avoidance and line-tracking system.

### Final Project Objectives
#### Final Project Primary Objectives
  1) Detect obstacles using ultrasonic sensors.
  2) Analyze sensor data and make real-time decisions to change direction.
  3) Implement motor control using the L293D motor driver.
  4) Display the car's current direction on an LCD screen.
  5) Utilize a servo motor for ultrasonic scanning within a 180° range.
  6) Implement line tracking using infrared sensors.
  7) Manage tasks efficiently with FreeRTOS for multitasking and real-time operation.
     
### Components and Materials
  * Ultrasonic HC-SR04 sensor: To detect obstacles in the car's path.
  * Servo motor: For scanning the environment using the ultrasonic sensor.
  * L293D motor driver: To control the speed and direction of the car's motors.
  * Motors: To drive the car's wheels.
  * Caster wheel: To provide stability to the car's chassis.
  * Chassis: The framework to hold all components securely.
  * Infrared sensors: For line tracking.
  * Microcontroller compatible with FreeRTOS.
  
### Project Implementation
  * Hardware Assembly: Assemble the chassis, attach the motors, and mount the caster wheel.
  * Ultrasonic Sensor Integration: Connect the ultrasonic sensor to the servo motor axis for scanning.
  * Motor Control: Integrate the L293D motor driver to control the car's movement.
  * LCD Integration: Connect the LCD display to show the car's current direction.
  * Software Development: Develop software to read ultrasonic sensor data, analyze it, control the motors, and implement line tracking.
  * Scanning Algorithm: Design an algorithm for the servo motor to scan the environment using the ultrasonic sensor.
  * Line Tracking Algorithm: Implement a line tracking algorithm using infrared sensors.
  * FreeRTOS Integration: Configure and integrate FreeRTOS for efficient multitasking and real-time control.
  * Testing and Calibration: Test the car's obstacle detection, avoidance, and line tracking capabilities. Calibrate the system for optimal performance.
  * Fine-tuning: Adjust parameters and algorithms to enhance the car's responsiveness and accuracy.
  
### Final Project Expected Outcomes
Upon successful completion of the project, we anticipate achieving the following outcomes:

1) A functional autonomous car capable of detecting obstacles, changing direction to avoid them, and tracking lines.
2) Real-time display of the car's direction on the LCD screen.
3) Smooth and accurate scanning of the environment using the servo motor and ultrasonic sensor.
4) Effective line tracking capabilities using infrared sensors.
5) Efficient multitasking and real-time operation with FreeRTOS.
   
### Final Project Conclusion
This final project aims to create an autonomous obstacle-avoidance and line-tracking car with the added capability of efficient multitasking and real-time operation using FreeRTOS. The final product will demonstrate advanced functionalities, making it suitable for various applications, including robotics and automation.

