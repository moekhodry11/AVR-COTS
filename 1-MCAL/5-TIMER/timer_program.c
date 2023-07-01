/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/07/2023      **********************/
/***************  SWC    : TIMER      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"
#include "DIO_interface.h"

/*Global Pointer to function */
static void (* TIMER_pvTimer0ISROFV)(void) = NULL;
static void (* TIMER_pvTimer0ISROCR)(void) = NULL;
static void (* TIMER_pvICUNotificationFunction)(void) = NULL;

/*********************************************************************************/
/* Function: TIMER_voidTimer0Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer0							       	    **/
/*********************************************************************************/
void TIMER_voidTimer0Init(void)
{
	#if WAVEFORM_GEN_MODE == NORMAL_MODE
	/*Set Timer 0 in NORMAL_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	//set the value initialtion of counter 

        #if ISR_ENABLE == ENABLE 
		SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_TOIE0);
		#elif ISR_ENABLE == DISENABLE 
		CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_TOIE0);
		#endif
		TIM0_u8_TCNT0_REG=START_TICK;
	#elif WAVEFORM_GEN_MODE == PWM_OR_PHASE_COTROL
	/*Set Timer 0 in PWM_OR_PHASE_COTROL Mode*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
		{
		case FAST_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
																	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																	break;
		case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
																	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																	break;
		case FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
																	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																	break;
		default: break;
		}
	//set the value clear comprt mathch 
	TIM0_u8_OCR0_REG=VALUE_OCR;
	#elif WAVEFORM_GEN_MODE == CTC_MODE
	/*Set Timer 0 in CTC_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	//set the value clear comprt mathch
	//TIM0_u8_OCR0_REG=VALUE_OCR;
	switch(OC0_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION:				/*Normal Port Operation*/
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH:	        /*Toggle OC0 on Compare Match*/
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	        /*Clear OC0 on Compare Match*/
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_SET_OC0_ON_COMPARE_MATCH:	            /*Set OC0 on Compare Match*/
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		default: break;
	}
        #if ISR_ENABLE == ENABLE
		SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_OCIE0);
		#elif ISR_ENABLE == DISENABLE 
		CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_OCIE0);
		#endif 
	//set the value clear compare match
	TIM0_u8_OCR0_REG=VALUE_OCR;
	#elif WAVEFORM_GEN_MODE == FAST_PWM_MODE
	/*Set Timer 0 in FAST_PWM_MODE*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
	case FAST_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	default: break;
	}
	//set the value clear comprt mathch 
	TIM0_u8_OCR0_REG=VALUE_OCR;
	#endif

    
	/*Set The Prescaler to be 8*/
	TIM0_u8_TCCR0_REG &= PRESCALER_MASK;
	TIM0_u8_TCCR0_REG |= PRESCALER_TYPE;
}

/*********************************************************************************/
/* Function: TIMER_u8Timer0SetCallBackOFV(void(*capy_pf)(void))                        				    **/
/* I/P Parameters: 	Pointer to Function							          		    **/
/* Returns:it returns Error stutes                                 				    **/
/* Desc:This Function Timer0 ISR 							       	    **/
/*********************************************************************************/
u8 TIMER_u8Timer0SetCallBackOFV(void(*capy_pf)(void))  
{
	u8 Local_u8ErrorStatus =STD_TYPES_OK;
	if(capy_pf!=NULL)
	{
		TIMER_pvTimer0ISROFV=capy_pf;

	}
	else 
	{
		Local_u8ErrorStatus =STD_TYPES_NOK;

	}
	return Local_u8ErrorStatus ;
}    
/*********************************************************************************/
/* Function:void __vector_11 (void) __attribute__((signal));
            void __vector_11 (void)                      				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:Function Sets the call back of Timer0 of over flow 	normal mode 						       	    **/
/*********************************************************************************/
/***********************************Timer0 ISR for over flow ***********************************/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u16 local_counter=0;
	local_counter++;
	if(local_counter==3907)
	{
		// clear countetr 
		local_counter=0;
		//update preload value
		TIM0_u8_TCNT0_REG=START_TICK;
		//call callback function from Applaction 
	    if(TIMER_pvTimer0ISROFV!=NULL)
	    {
		TIMER_pvTimer0ISROFV();	
	    }
	}
}
/*********************************************************************************/
/* Function: TIMER_u8Timer0SetCallBackOCR(void(*capy_pf)(void))                        				    **/
/* I/P Parameters: 	POinter to Function							          		    **/
/* Returns:it returns Error stutes                                				    **/
/* Desc:This Function Sets the call back of Timer0	CTC Mode  							       	    **/
/*********************************************************************************/
u8 TIMER_u8Timer0SetCallBackOCR(void(*capy_pf)(void))  
{
	u8 Local_u8ErrorStatus =STD_TYPES_OK;
	if(capy_pf!=NULL)
	{
		TIMER_pvTimer0ISROCR=capy_pf;
	}
	else 
	{
		Local_u8ErrorStatus =STD_TYPES_NOK;
	}
	return Local_u8ErrorStatus ;
} 
/*********************************************************************************/
/* Function:void __vector_10 (void) __attribute__((signal));
            void __vector_10 (void)                      				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Timer0 ISR  of  CTC Mode 							       	    **/
/*********************************************************************************/
/***********************************Timer0 ISR forCompare Match Event***********************************/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u16 local_counter=0;
	local_counter++;
	if(local_counter==10000)
	{
		// clear countetr 
		local_counter=0;
		
		//call callback function from Applaction 
	    if(TIMER_pvTimer0ISROCR!=NULL)
	    {
		TIMER_pvTimer0ISROCR();	

	    }
	}
	
}



/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1							       	    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void)
{
	#if  WAVEFORM_GEN_MODET1  == NORMAL_MODE
	/*Select The Normal Mode*/
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
    #elif  WAVEFORM_GEN_MODET1  == FAST_PWM_MODE
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
    #endif

	switch(OCR1A_ACTION)
			{
			case FAST_PWM_NORMAL_PORT_OPRETATION_OCR1A:						/*Normal Port Operation*/
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
																		break;
			case FAST_PWM_CLEAR_OCR1A_ON_COMPARE_MATCH__SET_OCR1A_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
																		break;
			case FAST_PWM_SET_OCR1A_ON_COMPARE_MATCH__CLEAR_OCR1A_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
																		break;
			default: break;
			}
	switch(OCR1B_ACTION)
			{
			case FAST_PWM_NORMAL_PORT_OPRETATION_OCR1B:						/*Normal Port Operation*/
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
																		break;
			case FAST_PWM_CLEAR_OCR1B_ON_COMPARE_MATCH__SET_OCR1B_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
																		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
																		break;
			case FAST_PWM_SET_OCR1B_ON_COMPARE_MATCH__CLEAR_OCR1B_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
																		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
																		break;
			default: break;
			}

	/*Set Prescaler to be 8*/
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS10);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS12);

}

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue)
{
	/*Set The Compare Value to the OCR0 Register*/
	TIM0_u8_OCR0_REG = Copy_u8CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel A Register*/
	TIM1_u16_OCR1A_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel B Register*/
	TIM1_u16_OCR1B_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/
/* Copy_u16CaptureValue Options: Capture value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue)
{
	/*Set The Input Capture Value to ICR1 Register*/
	TIM1_u16_ICR1_REG = Copy_u16CaptureValue;
}
/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/*********************************************************************************/
void ICU_voidInit(void)
{
	/*Set Trigger to rising edge initially*/
	SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_TCCR1B_ICES1);

	/*Enable The ICU Interrupt*/
	SET_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource)
{
	switch(Copy_u8TriggerSource)
	{
		case RISING_EDGE:
			/*Set The Rising Edge to be the trigger source*/
			SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		case FALLING_EDGE:
			/*Set The Falling Edge to be the trigger source*/
			CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		default:
			break;
	}
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/*********************************************************************************/
u16 ICU_u16ReadInputCapture(void)
{
	/*Get The Captured Value From ICR1 Register*/
	return TIM1_u16_ICR1_REG;
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void)
{
	/*Disable The ICU Interrupt*/
	CLR_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvacationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvacationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvacationFunction)(void))
{
	TIMER_pvICUNotificationFunction = *Copy_pvacationFunction;
}

/***********************************ISR for ICU Capture Event***********************************/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER_pvICUNotificationFunction != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvICUNotificationFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}
