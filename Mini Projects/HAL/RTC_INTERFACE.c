/*
 * RTC_INTERFACE.c
 *
 *
 *      Author: Remon Gerges
 */


#include "RTC_Private.h"
#include "RTC_INTERFACE.h"

#include "util/delay.h"
#include "LED_INTERFACING.h"
year_t date_res;
void RTC_Init(void)
{
	TWIconfig twi = {PRE_1,FREQ_100};

	TWI_init(&twi);
}


static uint8 RTC_dateFormat(uint8 copy_year_date){

	uint8 local_date =0;

	uint8 date_format[2];

	uint8 temp = copy_year_date;

	for(uint8 i=0;i<2;i++){

		date_format[i] = temp % 10;

		temp = temp / 10;

	}

	local_date = date_format[0] | (date_format[1]<<4);

	return local_date;
}

static uint8 RTC_dayFormat(uint8 copy_year_day){

	uint8 local_day = copy_year_day;

	return local_day;
}


static uint8 RTC_MonthFormat(uint8 copy_year_month){

	uint8 month_format[2];

	uint8 temp = copy_year_month;

	for(uint8 i=0;i<2;i++){

		month_format[i] = temp % 10;

		temp = temp / 10;

	}

	uint8 local_month = month_format[0] | (month_format[1] << 4);

	return local_month;
}

static uint8 RTC_yearFormat(uint8 copy_year){

	uint8 year_format[2];

	uint8 temp = copy_year;

	for(uint8 i=0;i<2;i++){

		year_format[i] = temp % 10;

		temp = temp / 10;

	}

	uint8 local_year = year_format[0] | (year_format[1] << 4);

	return local_year;
}


static uint8 RTC_TimeHrFormat(uint8 copy_time_HR , uint8 copy_time_format, uint8 copy_time_mode){

	uint8 local_HR_time =0;

	CLR_BIT(local_HR_time,7);

	uint8 HR_format[2];

	uint8 temp = copy_time_HR;

	for(uint8 i=0;i<2;i++){

		HR_format[i] = temp % 10;

		temp = temp / 10;
	}

	switch(copy_time_format){

	case time_format_12:

		SET_BIT(local_HR_time,6);

		switch(copy_time_mode){
		case AM:
			CLR_BIT(local_HR_time,5);

			break;
		case PM:
			SET_BIT(local_HR_time,5);
			break;
		}

		local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;

		local_HR_time &= 0b00011111;
		break;

		case time_format_24:

			CLR_BIT(local_HR_time,6);
			CLR_BIT(local_HR_time,5);
			local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;

			local_HR_time &= 0b00111111;
			break;

	}



	//	local_HR_time |= ( HR_format[0] | ( HR_format[1] <<4)) ;

	return local_HR_time;

}



static uint8 RTC_ADJUSTSecMin(uint8 data)
{
	uint8 local_sec_time = 0;

	CLR_BIT(local_sec_time,7);

	uint8 Sec_format[2];

	uint8 temp = data;

	for(uint8 i=0;i<2;i++){

		Sec_format[i] = temp % 10;

		temp = temp / 10;

	}

	local_sec_time |=  Sec_format[0]  | ( Sec_format[1]<<4);

	return local_sec_time;
}



uint8 RTC_setTime(time_t* time)
{


	//Start Condtion
	TWI_start();
	//	if (TWI_getStatus() != MT_MODE_START)
	//		return 0;

	//Send the slave address
	TWI_writeByte(0xD0);
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;

	//Send the Write is 0
	TWI_writeByte(0x00);
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;


	//Sending sec and minutes and hours
	TWI_writeByte(RTC_ADJUSTSecMin(time->second));
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;

	TWI_writeByte(RTC_ADJUSTSecMin(time->minute));
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;

	TWI_writeByte(RTC_TimeHrFormat(time->hour,time->time_format,time->time_mode));
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;

	TWI_stop();


	return 1;

}


uint8 RTC_getTime(time_t* ptr_time)
{
	//Start Condtion
	TWI_start();
	//	if (TWI_getStatus() != MT_MODE_START)
	//		return 0;

	//Send the slave address
	TWI_writeByte(0xD0);
	//	if (TWI_getStatus() != MT_MODE_SLAVE_WRITE_ACK)
	//		return 0;

	//Send the write is 1
	TWI_writeByte(0x00);
	if (TWI_getStatus() != MT_MODE_DATA_TRANSMITTED_ACK)
		return 0;


	//Repeated start Start Condtion
	TWI_start();
	if (TWI_getStatus() != MT_MODE_REP_START)
		return 0;

	//Send the Read is 1
	TWI_writeByte(0xD1);
	if (TWI_getStatus() != MR_MODE_SLAVE_READ_ACK)
		return 0;


	uint8 sec;
	uint8 min;
	uint8 hr;


	uint8 ptr_time_receive;
	TWI_readByteWithACK(&ptr_time_receive);
	sec = ptr_time_receive;

	TWI_readByteWithACK(&ptr_time_receive);
	min = ptr_time_receive;
	TWI_readByteWithNACK(&ptr_time_receive);
	hr = ptr_time_receive;
	TWI_stop();


	uint8 temp= sec >> 4;
	temp*= 10;
	sec= (sec & 0x0f) + temp;

	temp= min >> 4;
	temp*= 10;
	min= (min & 0x0f) + temp;

	temp= hr >> 4;
	temp*= 10;
	hr= (hr & 0x0f) + temp;

	ptr_time->second = sec;

	ptr_time->minute = min;

	ptr_time->hour = hr;

	if( (GET_BIT(hr,6) == 1) ){

		ptr_time->time_format = time_format_12;

		if( (GET_BIT(hr,5) == 1) ){

			ptr_time->time_mode = PM;

		}
		else if( ( GET_BIT(hr,5) == 0 ) ) {
			ptr_time->time_mode = AM;
		}
		else{

			// do nothing , error type
		}
	}

	else if( (GET_BIT(hr,6) == 0) ){

		ptr_time->time_format = time_format_24;
		ptr_time->time_mode = No_TYPE;
	}
	return 1;
}



/* this function should take date in (year month day )and should configure RTC with it -> */
void RTC_SetDate(year_t* copy_year){

	/* Data year handling */

	uint8 day_res_send = RTC_dayFormat(copy_year->day);

	uint8 date_res_send = RTC_dateFormat(copy_year->date);

	uint8 month_res_send = RTC_MonthFormat(copy_year->month);

	uint8 year_res_send = RTC_yearFormat(copy_year->year);


	/* start sending data */
	TWI_start();

	TWI_writeByte(0xD0);

	TWI_writeByte(0x03);

	TWI_writeByte(day_res_send);
	TWI_writeByte(date_res_send);

	TWI_writeByte(month_res_send);

	TWI_writeByte(year_res_send);

	TWI_stop();



}

/* this function should return the data in (year month day)-> */
year_t  RTC_GetDate(void){


	/* start Receiving data */

	TWI_start();
	TWI_writeByte(0xD0);
	TWI_writeByte(0x03);

	TWI_start();

	TWI_writeByte(0xD1);


	uint8 ptr_date_receive;

	TWI_readByteWithACK(&ptr_date_receive);

	uint8 date_day = ptr_date_receive;

	TWI_readByteWithACK(&ptr_date_receive);

	uint8 date = ptr_date_receive;

	TWI_readByteWithACK(&ptr_date_receive);

	uint8 date_month = ptr_date_receive;

	TWI_readByteWithNACK(&ptr_date_receive);

	uint8 date_year = ptr_date_receive;

	TWI_stop();

	/* Data handling to return date */

	date_res.day = date_day;
	date_res.date = date;
	date_res.month = date_month;
	date_res.year = date_year;

	return date_res;

}



