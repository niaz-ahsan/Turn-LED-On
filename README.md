# Turn-LED-On

LD4 from STM32F4DISC board is turned on in this exercise.

From schematic the LD4 is connected with PD12 of MCU. To manipulate the external ports of MCU we need to manipulate General Purpose I/o (GPIO) peripheral of the MCU.
In this case it's GPIO D. 

Process:
1. Enable GPIO peripheral by RCC Clock Registers
2. Set o/p mode for port D pins
3. Mention which pin should be enabled with high voltage (~3.3v)

By base address and address offset we found the exact regusters to work with and grabbed them using pointers. Later we set necessary values inside the register to get
expected o/p.
