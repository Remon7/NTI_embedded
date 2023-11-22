/*
 * RTC_INTERFACE.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Remon Gerges
 */

#ifndef INC_RTC_INTERFACE_H_
#define INC_RTC_INTERFACE_H_

#define RTC_Slave_Address_W   0b11010000
#define RTC_Slave_Address_R   0b11010001


#include "TWI_INTERFACE.h"


#define RTC_address_0       0
#define RTC_address_1       1
#define RTC_address_2       2
#define RTC_address_3       3
#define RTC_address_4       4
#define RTC_address_5       5
#define RTC_address_6       6
#define RTC_address_7       7



typedef enum{
	time_format_24 = 0,
	time_format_12 = 1
}time_format_t;

typedef enum{
	AM =0,
	PM =1,
	No_TYPE =2
}time_mode_t;


typedef struct{
	uint8 hour;
	uint8 minute;
	uint8 second;
	time_format_t time_format;
	time_mode_t time_mode;

}time_t;



typedef struct{
	uint16 year;
	uint8 month;
	uint8 date;
	uint8 day;
}year_t;




void RTC_Init(void);


uint8 RTC_setTime(time_t* time);
uint8 RTC_getTime(time_t* ptr_time);
void RTC_SetDate(year_t* copy_year);

year_t  RTC_GetDate(void);
#endif /* INC_RTC_INTERFACE_H_ */
