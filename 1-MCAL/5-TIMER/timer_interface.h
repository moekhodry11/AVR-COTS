/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/07/2023      **********************/
/***************  SWC    : TIMER      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
/*********************************** Timer0 ***********************************/
/*the  Macros of timer mode */
#define    NORMAL_MODE      			                            0
#define    PWM_OR_PHASE_COTROL                                      1
#define    CTC_MODE                                                 2
#define    FAST_PWM_MODE                                            3
/*the  Macros of timer mode  
 by Compare Output Mode non-PWM Mode */

#define    NON_PWM_NORMAL_PORT_OPRETATION                           0
#define    NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                      1
#define    NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                       2
#define    NON_PWM_SET_OC0_ON_COMPARE_MATCH						    3

/*the  Macros of timer mode  
 by Compare Output Mode  by PWM Mode */   
#define    FAST_PWM_NORMAL_PORT_OPRETATION                          0
#define    FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP      1
#define    FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	  	2

/*the  Macros of prescaler */   
#define    CLK_DIV_BY_0										 	    1
#define    CLK_DIV_BY_8										 	    2
#define    CLK_DIV_BY_64                                            3
#define    CLK_DIV_BY_256                                           4
#define    CLK_DIV_BY_1024                                          5
#define    ECS_ON_T0_FALLING_EDGE      								6
#define    ECS_ON_T0_RISING_EDGE       								7
/*he macro count of resing or Falling*/
#define	   RISING_EDGE												0
#define	   FALLING_EDGE												1
/**************************TIMER 1 **************************************/
#define FAST_PWM_NORMAL_PORT_OPRETATION_OCR1B                       1
#define FAST_PWM_CLEAR_OCR1B_ON_COMPARE_MATCH__SET_OCR1B_ON_TOP     2
#define FAST_PWM_SET_OCR1B_ON_COMPARE_MATCH__CLEAR_OCR1B_ON_TOP     3

#define FAST_PWM_NORMAL_PORT_OPRETATION_OCR1A                       4
#define FAST_PWM_CLEAR_OCR1A_ON_COMPARE_MATCH__SET_OCR1A_ON_TOP     5
#define FAST_PWM_SET_OCR1A_ON_COMPARE_MATCH__CLEAR_OCR1A_ON_TOP     6

/*****************************************************************************/
/* Function: TIMER_voidTimer0Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer0							       	    **/
/*********************************************************************************/
void TIMER_voidTimer0Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1							       	    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/

void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue);

/*********************************************************************************/
/* Function: TIMER_u8Timer0SetCallBackOFV		               				    **/
/* I/P Parameters: void(*capy_pf)(void)		   		                            **/
/* Returns:it returns error status                                			    **/
/* Desc:This Function Sets the call back of Timer0							  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
u8 TIMER_u8Timer0SetCallBackOFV(void(*capy_pf)(void))  ;

/*********************************************************************************/
/* Function: TIMER_u8Timer0SetCallBackOCR		               				    **/
/* I/P Parameters: void(*capy_pf)(void)		   		                            **/
/* Returns:it returns error status                                			    **/
/* Desc:This Function Sets the call back of Timer0 CTC mode 	              	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
u8 TIMER_u8Timer0SetCallBackOCR(void(*capy_pf)(void))  ;

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/

void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/

void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/

void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue);

/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/*********************************************************************************/
void ICU_voidInit(void);

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/********************************************************************************/
u16 ICU_u16ReadInputCapture(void);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void);

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvacationFunction)(void));


#endif
