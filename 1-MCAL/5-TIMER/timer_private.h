/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/07/2023      **********************/
/***************  SWC    : TIMER      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* Define for Timer Registers */
/**************************************************************************************************/
/****************************************** TIMER 0 REGISTERS *************************************/
/**************************************************************************************************/
#define     TIM0_u8_TCCR0_REG		      *((volatile u8 *)(0x53))		// Timer/Counter0 Control Register
/*the macro define pin in Register TCCR0 */
#define     TIM0_u8_TCCR0_FOC0            7								// Force On Compare
#define     TIM0_u8_TCCR0_WGM00           6                             // Wave Generation Mode 0
#define     TIM0_u8_TCCR0_COM01           5                             // Compare match output mode 1
#define     TIM0_u8_TCCR0_COM00           4                             // Compare match output mode 0
#define     TIM0_u8_TCCR0_WGM01           3                             // Wave Generation Mode 1
#define     TIM0_u8_TCCR0_CS02            2                             // Clock Select 02
#define     TIM0_u8_TCCR0_CS01            1                             // Clock Select 01
#define     TIM0_u8_TCCR0_CS00            0                             // Clock Select 00


#define     TIM0_u8_TCNT0_REG		      *((volatile u8 *)(0x52))		// Timer/Counter0 Register

#define     TIM0_u8_OCR0_REG		      *((volatile u8 *)(0x5C))		// Output Compare0 Register

#define     TIM0_u8_TIMSK_REG		      *((volatile u8 *)(0x59))		// Timer0 Mask Register
/*the macro define pin in Register TIMSK */
#define     TIM0_u8_TIMSK_TOIE0           0								// Timer Overflow Interrupt Enable
#define     TIM0_u8_TIMSK_OCIE0           1                             // Timer On Compare Interrupt Enable
#define		TIM0_u8_TIMSK_TOIE1		      2								// Timer/Counter1 Overflow Interrupt Enable
#define		TIM0_u8_TIMSK_OCIE1B	      3								// Timer/Counter1 Output Compare B Interrupt Enable
#define		TIM0_u8_TIMSK_OCIE1A	      4								// Timer/Counter1 Output Compare A Interrupt Enable
#define		TIM0_u8_TIMSK_TICIE1	      5								// Timer/Counter1 Input Capture Interrupt Enable
#define     TIM0_u8_TIMSK_TOIE2           6								// Timer/Counter2 Overflow Interrupt Enable
#define     TIM0_u8_TIMSK_OCIE2           7								// Timer/Counter2 Output Compare Interrupt Enable

#define     TIM0_u8_TIFR_REG              *((volatile u8 *)(0x58))		// Timer/Counter0 Interrupt Flag Register
/*the macro define pin in Register TIFR */
#define     TIM0_u8_TIFR_TOV0             0								// Timer/Counter0 Overflow flag
#define     TIM0_u8_TIFR_OCF0             1                             // Timer/Counter0 Output Compare flag
#define		TIM0_u8_TIFR_TOV1		      2								// Timer/Counter1 Overflow Flag
#define		TIM0_u8_TIFR_OCF1B		      3								// Timer/Counter1 Output Compare B Flag
#define		TIM0_u8_TIFR_OCF1A		      4								// Timer/Counter1 Output Compare A Flag
#define		TIM0_u8_TIFR_ICF1		      5								// Timer/Counter1 Input Capture Flag
#define     TIM0_u8_TIFR_TOV2             6								// Timer/Counter2 Overflow flag
#define     TIM0_u8_TIFR_OCF2             7                             // Timer/Counter2 Output Compare flag


/**************************************************************************************************/
/****************************************** TIMER 1 REGISTERS *************************************/
/**************************************************************************************************/
#define		TIM1_u8_TCCR1A_REG			  *((volatile u8 *)(0x4F))		// Timer/Counter 1 Control Register A
/*the macro define pin in Register TCCR1A */
#define     TIM1_u8_TCCR1A_WGM10	      0								// Wave Generation Mode 0 Bit
#define     TIM1_u8_TCCR1A_WGM11	      1								// Wave Generation Mode 1 Bit
#define     TIM1_u8_TCCR1A_FOC1B	      2								// Force Output Compare B Bit
#define     TIM1_u8_TCCR1A_FOC1A	      3								// Force Output Compare A Bit
#define     TIM1_u8_TCCR1A_COM1B0	      4								// Compare Output Mode Channel B 0 Bit
#define     TIM1_u8_TCCR1A_COM1B1	      5								// Compare Output Mode Channel B 1 Bit
#define     TIM1_u8_TCCR1A_COM1A0	      6								// Compare Output Mode Channel A 0 Bit
#define     TIM1_u8_TCCR1A_COM1A1	      7								// Compare Output Mode Channel A 1 Bit


#define		TIM1_u8_TCCR1B_REG			  *((volatile u8 *)(0x4E))		// Timer/Counter 1 Control Register B
/*the macro define pin in Register TCCR1B */
#define     TIM1_u8_TCCR1B_CS10			  0								// Clock Selection 0 Bit
#define     TIM1_u8_TCCR1B_CS11			  1								// Clock Selection 1 Bit
#define     TIM1_u8_TCCR1B_CS12			  2								// Clock Selection 2 Bit
#define     TIM1_u8_TCCR1B_WGM12 		  3								// Wave Generation Mode 2 Bit
#define     TIM1_u8_TCCR1B_WGM13		  4								// Wave Generation Mode 3 Bit
#define     TIM1_u8_TCCR1B_ICES1		  6								// Input Capture Edge Select
#define     TIM1_u8_TCCR1B_ICNC1		  7								// Input Capture Noise Canceler


#define		TIM1_u8_TCNT1L_REG			  *((volatile u8 *)(0x4C))		// Timer/Counter 1 Low Register
#define		TIM1_u8_TCNT1H_REG			  *((volatile u8 *)(0x4D))		// Timer/Counter 1 High Register
#define		TIM1_u16_TCNT1_REG			  *((volatile u16 *)(0x4C))		// Timer/Counter 1 Register

#define		TIM1_u8_OCR1AL_REG			  *((volatile u8 *)(0x4A))		// Output Compare 1 Channel A Low Register
#define		TIM1_u8_OCR1AH_REG			  *((volatile u8 *)(0x4B))		// Output Compare 1 Channel A High Register
#define     TIM1_u16_OCR1A_REG			  *((volatile u16 *)(0x4A))		// Output Compare 1 Channel A Register

#define		TIM1_u8_OCR1BL_REG			  *((volatile u8 *)(0x48))		// Output Compare 1 Channel B Low Register
#define		TIM1_u8_OCR1BH_REG			  *((volatile u8 *)(0x49))		// Output Compare 1 Channel B High Register
#define     TIM1_u16_OCR1B_REG			  *((volatile u16 *)(0x48))		// Output Compare 1 Channel B Register

#define		TIM1_u8_ICR1L_REG			  *((volatile u8 *)(0x46))		// Input Capture 1 Low Register
#define		TIM1_u8_ICR1H_REG			  *((volatile u8 *)(0x47))		// Input Capture 1 High Register
#define     TIM1_u16_ICR1_REG			  *((volatile u16 *)(0x46))		// Input Capture 1 Register

#define 	 PRESCALER_MASK     0b11111000

#define ENABLE    1

#define DISABLE   0
#endif
