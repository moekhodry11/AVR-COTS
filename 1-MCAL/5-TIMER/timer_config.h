/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/07/2023      **********************/
/***************  SWC    : TIMER      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H
/**************** ************* timer 0 *******************************/
/**************************************************************************************************/
/**WAVEFORM_GEN_MODE options*/
/* 			  	           1-  NORMAL_MODE                                                */
/*                         2-  PWM_OR_PHASE_COTROL                                        */
/*                         3-  CTC_MODE                                                   */
/*                         4-  FAST_PWM_MODE                                              */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	  WAVEFORM_GEN_MODE          NORMAL_MODE

/* configeur the value to intialation timer to start counting  */

#define    START_TICK  192                               /*value the  1 sec */

/* configeur the value compare math to intialation */

#define    VALUE_OCR  99                                 /*value the  1 sec */

/*********************************Control action on OC0 pin****************************************/
/**********************************for Non-PWM Mode options****************************************/
/* 			  	                        1-  NON_PWM_NORMAL_PORT_OPRETATION                         */
/*                                      2-  NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                    */
/*                                      3-  NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                     */
/*                                      4-  NON_PWM_SET_OC0_ON_COMPARE_MATCH                       */
/**************************************************************************************************/
/***********************************CTC MODE options******************************************/
/*********************************** FAST_PWM_MODE options And PWM_OR_PHASE_COTROL options *****************/
/*  0  FAST_PWM_NORMAL_PORT_OPRETATION                                                            */
/*  1  FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP    (non inverted mode)                 */
/*  2  FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	   (inverted mode)
 *                                                                                                */
/**************************************************************************************************/
/**************************************************************************************************/

#define 	 OC0_ACTION                 NON_PWM_NORMAL_PORT_OPRETATION


/**************************************************************************************************/
/**********************************PRESCALER_TYPE options******************************************/
/* 	TIMER_COUNTER_DISABLED              No clock source (Timer/Counter stopped).                  */
/*  CLK_DIV_BY_0				        (No   prescaling)                                         */
/*  CLK_DIV_BY_8				        (From prescaler)                                          */
/*  CLK_DIV_BY_64                       (From prescaler)                                          */
/* 	CLK_DIV_BY_256                      (From prescaler)                                          */
/*  CLK_DIV_BY_1024                     (From prescaler)                                          */
/*  ECS_ON_T0_FALLING_EDGE              External clock source on T0 pin. Clock on falling edge.   */
/*  ECS_ON_T0_RISING_EDGE               External clock source on T0 pin. Clock on rising edge     */
/* 	ECS_ON_T1_FALLING_EDGE              External clock source on T1 pin. Clock on falling edge.   */
/*  ECS_ON_T1_RISING_EDGE               External clock source on T1 pin. Clock on rising edge     */
/**************************************************************************************************/
/**************************************************************************************************/

#define 	 PRESCALER_TYPE     CLK_DIV_BY_8

/*the macro to configure want to work ISR or not in mode  ctc and normal mode
opation : 1-ENABLE 
          2- DISABLE */
#define 	 ISR_ENABLE    ENABLE




/*****************************Timer1**************************************/

/**************************************************************************************************/
/**WAVEFORM_GEN_MODE options*/
/* 			  	           1-  NORMAL_MODE                                                */
/*                         4-  FAST_PWM_MODE    OCR1B_ACTION                                          */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	  WAVEFORM_GEN_MODET1          NORMAL_MODE

/*********************************Control action on OC0 pin****************************************/
/**********************************for Non-PWM Mode options****************************************/
/* 			  	                    1-  NORMAL_MODE                                               */
/*                                  2-  PWM_OR_PHASE_COTROL                                      */
/*                                  3-  CTC_MODE                                                 */
/*                                  4-  FAST_PWM_MODE                                             */
/**************************************************************************************************/
/***********************************CTC MODE options******************************************/
 /* 1-  NON_PWM_NORMAL_PORT_OPRETATION
    2-  NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH
    3-  NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH
    4-  NON_PWM_SET_OC0_ON_COMPARE_MATCH

/*********************************** FAST_PWM_MODE options And PWM_OR_PHASE_COTROL options *****************/
/*  0  FAST_PWM_NORMAL_PORT_OPRETATION_OCR1B                                                            */
/*  1  FAST_PWM_CLEAR_OCR1B_ON_COMPARE_MATCH__SET_OCR1B_ON_TOP    (non inverted mode)                 */
/*  2  FAST_PWM_SET_OCR1B_ON_COMPARE_MATCH__CLEAR_OCR1B_ON_TOP	   (inverted mode)
 *  0  FAST_PWM_NORMAL_PORT_OPRETATION_OCR1A                                                           */
/*  1  FAST_PWM_CLEAR_OCR1A_ON_COMPARE_MATCH__SET_OCR1A_ON_TOP    (non inverted mode)                 */
/*  2  FAST_PWM_SET_OCR1A_ON_COMPARE_MATCH__CLEAR_OCR1A_ON_TOP	   (inverted mode)
                */
/**************************************************************************************************/
/**************************************************************************************************/

#define 	 OCR1A_ACTION                 NON_PWM_NORMAL_PORT_OPRETATION

#define 	 OCR1B_ACTION                 NON_PWM_NORMAL_PORT_OPRETATION



#endif
