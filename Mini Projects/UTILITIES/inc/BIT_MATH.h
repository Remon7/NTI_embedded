/*
 * BIT_MATH.h
 *
 *
 *  Author: Remon Gerges
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(register_name,bit_no)  			(register_name |= (1<<bit_no))
#define CLR_BIT(register_name,bit_no)  			(register_name &= ~(1<<bit_no))
#define TOGGLE_BIT(register_name,bit_no) 		(register_name ^= (1<<bit_no))
#define GET_BIT(register_name,bit_no)  			((register_name & (1<<bit_no)) >>bit_no)

#define RSHFT_REG(register_name,bit_no)			(register_name>>bit_no)
#define LSHFT_REG(register_name,bit_no)			(register_name<<bit_no)
#define CRSHFT_REG(register_name,bit_no)		(~(register_name>>bit_no))
#define CLSHFT_REG(register_name,bit_no)		(~(register_name<<bit_no))

#define ASSIGN_REG(register_name,value)			(register_name=value)
#define SET_REG(register_name)  			(register_name |= 0xFF)
#define CLR_REG(register_name)  			(register_name &= 0)
#define TOGGLE_REG(register_name,bit_no) 		(register_name ^= 0xFF)

#define SET_H_NIB(register_name)                        (register_name |= 0xF0)
#define SET_L_NIB(register_name)                        (register_name |= 0x0F)
#define CLR_H_NIB(register_name)                        (register_name &= 0x0F)
#define CLR_L_NIB(register_name)                        (register_name &= 0xF0)
#define GET_H_NIB(register_name)                        ((register_name &  0xF0) >> 4)  // if register 8 bits (if 16 bit  >>8)
#define GET_L_NIB(register_name)                        (register_name &  0x0F)
#define ASSIGN_H_NIB(register_name,value)               ((register_name &=  0x0F) | (value<<4))
#define ASSIGN_L_NIB(register_name)                     ((register_name &=  0xF0) | value)
#define TOGGLE_H_NIB(register_name,value)               (register_name ^=  0xF0)
#define TOGGLE_L_NIB(register_name)                     (register_name ^=  0x0F)
#define SWAP_NIB(register_name)				( ((register_name &  0xF0) >> 4) | ((register_name &  0x0F) << 4) )













#endif /* BIT_MATH_H_ */
