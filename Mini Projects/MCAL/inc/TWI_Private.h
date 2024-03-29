/*
 * TWI_Private.h
 *
 *
 *      Author: Remon Gerges
 */

#ifndef INC_TWI_PRIVATE_H_
#define INC_TWI_PRIVATE_H_



#define Pre_Mask									0xF8
#define Masking_To_Eliminate_First_3bits			0xF8


///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TWBR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define TWBR7			7
#define TWBR6			6
#define TWBR5			5
#define TWBR4			4
#define TWBR3			3
#define TWBR2			2
#define TWBR1			1
#define TWBR0			0



///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TWCR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define TWINT			7
#define TWEA			6
#define TWSTA			5
#define TWSTO			4
#define TWWC			3
#define TWEN			2
// Reserved bit 1
#define TWIE			0



///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TWSR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define TWS7			7
#define TWS6			6
#define TWS5			5
#define TWS4			4
#define TWS3			3
// Reserved bit 2
#define TWPS1			1
#define TWPS0			0


///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TWDR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define TWD7			7
#define TWD6			6
#define TWD5			5
#define TWD4			4
#define TWD3			3
#define TWD2			2
#define TWD1			1
#define TWD0			0


///////////////////////////////////////////////////////////////////////////////
///////////////////////////// DEFINING TWDR Reg Bits//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define TWA6			7
#define TWA5			6
#define TWA4			5
#define TWA3			4
#define TWA2			3
#define TWA1			2
#define TWA0			1
#define TWGCE			0




#endif /* INC_TWI_PRIVATE_H_ */
