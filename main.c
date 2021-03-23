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

	// setting 3rd bit of RCC Clock register to enable GPIO D peripheral
	*RCC_clock |= (1 << 3);

	// 24,25 bit position of GPIO D Mode Register should be 0 and 1.
	// First, clear 25 bit position
	*GPIO_D_mode &= ~(1 << 25);
	// set 24 bit position
	*GPIO_D_mode |= (1 << 24);

	// setting 12 bit position of GPIO D o/p data
	*GPIO_D_output_data |= (1 << 12);

	for(;;);
}
