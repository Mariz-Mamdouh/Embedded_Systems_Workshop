# IEEE Embedded Systems Workshop: Microcontroller Architecture and Interfacing with ARM Cortex
## Workshop content:
1) C-Language Basics.
2) Advanced C Programming: pointers,macros,processor architecture and memory types.
3) ARM Architecture.
4) Microcontroller Peripherals.
5) Real-Time Scheduling.
6) Communucation interfaces: UART,SPI...etc.
7) Hands-On Practice.

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
