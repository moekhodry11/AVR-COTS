/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 09/02/2023      **********************/
/***************  SWC    : EXTI            **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndix,u8 Copy_u8EdgeIndix){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8EXTIIndix){
		case EXTI_u8_INT0:
			switch(Copy_u8EdgeIndix){
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,1);
					SET_BIT(EXTI_u8_MCUCR,0);
					/* Enable EXTI0 */
					SET_BIT(EXTI_u8_GICR,6);
				break;
				
				case EXTI_u8_FALLING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,1);
					CLR_BIT(EXTI_u8_MCUCR,0);
					/* Enable EXTI0 */
					SET_BIT(EXTI_u8_GICR,6);
				break;
				
				case EXTI_u8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_u8_MCUCR,1);
					SET_BIT(EXTI_u8_MCUCR,0);
					/* Enable EXTI0 */
					SET_BIT(EXTI_u8_GICR,6);
				break;
				
				case EXTI_u8_LOW_LEVEL:
					CLR_BIT(EXTI_u8_MCUCR,1);
					CLR_BIT(EXTI_u8_MCUCR,0);
					/* Enable EXTI0 */
					SET_BIT(EXTI_u8_GICR,6);
				break;
				
				default : Local_u8ErrorState= STD_TYPES_NOK;
			}
		break;
		
		case EXTI_u8_INT1:
			switch(Copy_u8EdgeIndix){
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,3);
					SET_BIT(EXTI_u8_MCUCR,2);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,7);
				break;
				
				case EXTI_u8_FALLING_EDGE:
					SET_BIT(EXTI_u8_MCUCR,3);
					CLR_BIT(EXTI_u8_MCUCR,2);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,7);
				break;
				
				case EXTI_u8_ANY_LOGICAL_CHANGE:
					CLR_BIT(EXTI_u8_MCUCR,3);
					SET_BIT(EXTI_u8_MCUCR,2);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,7);
				break;
				
				case EXTI_u8_LOW_LEVEL:
					CLR_BIT(EXTI_u8_MCUCR,3);
					CLR_BIT(EXTI_u8_MCUCR,2);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,7);
				break;
				
				default : Local_u8ErrorState= STD_TYPES_NOK;
			}
		break;
		
		case EXTI_u8_INT2:
			switch(Copy_u8EdgeIndix){
				case EXTI_u8_RAISING_EDGE:
					SET_BIT(EXTI_u8_MCUCSR,6);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,5);
				break;
				
				case EXTI_u8_FALLING_EDGE:
					CLR_BIT(EXTI_u8_MCUCSR,6);
					/* Enable EXTI1 */
					SET_BIT(EXTI_u8_GICR,5);
				break;
				
				default : Local_u8ErrorState= STD_TYPES_NOK;
			}
		break;
		default : Local_u8ErrorState= STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

//u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndix){
//
//}

/* Global Array pointer to function */
static void (*EXTI_ApfExti[3])(void)={NULL,NULL,NULL};

u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndix, void(*Copy_pf)(void)){
	u8 Local_u8ErrorState= STD_TYPES_OK;
	if((Copy_u8EXTIIndix <= EXTI_u8_INT2) && (Copy_pf != NULL) ){
		EXTI_ApfExti[Copy_u8EXTIIndix]=Copy_pf;
	}else{
		Local_u8ErrorState= STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

	/* Tog_Led();//cant call a funcion from application layer
	so we have to use call back function (pointer to function)
	*/
/* Prototype for ISR of EXTI0 */
void __vector_1(void)			__attribute__((signal));
void __vector_1(void){
	if(EXTI_ApfExti[EXTI_u8_INT0] != NULL){
		EXTI_ApfExti[EXTI_u8_INT0]();
	}
}

/* Prototype for ISR of EXTI1 */
void __vector_2(void)			__attribute__((signal));
void __vector_2(void){
	if(EXTI_ApfExti[EXTI_u8_INT1] != NULL){
		EXTI_ApfExti[EXTI_u8_INT1]();
	}
}

/* Prototype for ISR of EXTI2 */
void __vector_3(void)			__attribute__((signal));
void __vector_3(void){
	if(EXTI_ApfExti[EXTI_u8_INT2] != NULL){
		EXTI_ApfExti[EXTI_u8_INT2]();
	}
}
