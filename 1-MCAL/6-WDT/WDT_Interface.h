/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 03/07/2023      **********************/
/***************  SWC    : WDT      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


#define TIMEOUT_16_3_MS		0
#define TIMEOUT_32_5_MS		1
#define TIMEOUT_65_MS		2
#define TIMEOUT_0_13_S		3
#define TIMEOUT_0_26_S		4
#define TIMEOUT_0_52_S		5
#define TIMEOUT_1_0_S		6
#define TIMEOUT_2_1_S		7

/*********************************************************************************/
/* Function: WDT_voidEnable			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables watch dog timer						       	    **/
/*********************************************************************************/
void WDT_voidEnable(void);

/*********************************************************************************/
/* Function: WDT_voidDisable		                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables watch dog timer						       	    **/
/*********************************************************************************/
void WDT_voidDisable(void);

/*********************************************************************************/
/* Function: WDT_voidSleep			                        				    **/
/* I/P Parameters: Copy_u8SleepTimeOut						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function makes the WDT sleeps for a specific timeout		       	**/
/*********************************************************************************/
/* Copy_u8SleepTimeOut Options: TIMEOUT_16_3_MS									**/
/*								TIMEOUT_32_5_MS									**/
/*								TIMEOUT_65_MS									**/
/*								TIMEOUT_0_13_S									**/
/*								TIMEOUT_0_26_S									**/
/*								TIMEOUT_0_52_S									**/
/*								TIMEOUT_1_0_S									**/
/*								TIMEOUT_2_1_S									**/
/*********************************************************************************/
void WDT_voidSleep(u8 Copy_u8SleepTimeOut);

#endif
