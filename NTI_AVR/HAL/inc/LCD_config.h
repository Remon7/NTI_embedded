/*
 * LCD_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: remon
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DATA_BIT_MODE	4

#if((LCD_DATA_BIT_MODE != 4) && (LCD_DATA_BIT_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif


/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA_BASE
#define LCD_RS_PIN_ID                  PIN3

#define LCD_E_PORT_ID                  PORTA_BASE
#define LCD_E_PIN_ID                   PIN2

#define LCD_DATA_PORT_ID               PORTB_BASE



/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_ENTRY_RIGHT                0x06
#define LCD_ENTRY_LEFT                 0x04
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


#define GET_BIT(register_name,bit_no)  			((register_name & (1<<bit_no)) >>bit_no)

#endif /* LCD_CONFIG_H_ */
