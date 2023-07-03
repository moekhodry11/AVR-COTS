/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 03/07/2023      **********************/
/***************  SWC    : WDT      	   **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "WDT_Interface.h"
#include "WDT_Private.h"
#include "WDT_Config.h"

/*********************************************************************************/
/* Function: WDT_voidEnable			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables watch dog timer						       	    **/
/*********************************************************************************/
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR, WDTCR_WDE);
}

/*********************************************************************************/
/* Function: WDT_voidDisable		                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables watch dog timer						       	    **/
/*********************************************************************************/
void WDT_voidDisable(void)
{
	/*Set WDTOE and WDE in the same operation*/
	WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);	
	/*Within The Next Four Clock Cycles, Write Logic 0 to WDE*/
	WDTCR = 0x00;
}

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
void WDT_voidSleep(u8 Copy_u8SleepTimeOut)
{
	if(Copy_u8SleepTimeOut < MAX_NUMBER_FOR_PRESCALER)
	{
		WDTCR &= PRESCALER_RESET_MASK;
		WDTCR |= Copy_u8SleepTimeOut;
	}
	else
	{
		//Do Nothing
	}
}






