/**
 ******************************************************************************
 Problem statement: Turn on LD4 (Green LED)
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	uint32_t *RCC_clock = (uint32_t*) 0x40023830; // RCC_AHB1ENR Address
	uint32_t *GPIO_D_mode = (uint32_t*) 0x40020C00; // GPIO D Mode Register Address
	uint16_t *GPIO_D_output_data = (uint16_t*) 0x40020C14; // GPIO D O/P Data Register Address

	*RCC_clock = 8; // Turning on GPIO D pin that's 3rd bit
	*GPIO_D_mode = 0b00000001000000000000000000000000; // O/P Mode for PD12 pin
	*GPIO_D_output_data = 0b0001000000000000; // Turn on PD12 pin

	for(;;);
}
