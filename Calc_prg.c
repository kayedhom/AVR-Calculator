/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/****************File: Calc_prg.c**********************/
/******************Date: 8th Sep 2022******************/
/*********************Version: V1**********************/
/***********Desc:functions'definitions ***************/
/******************************************************/
/******************************************************/



#include"STD_TYPES.h"
#include"Error_state.h"
#include "DIO_interface.h"
#include"7segments_interface.h"
#include"Calc_private.h"
#include <avr/delay.h>


error_state CALC_U8DisplaySum(u8 Copy_U8PortLEFT,u8 Copy_U8PortRIGHT,u8 Copy_U8FirstNumber, u8 Copy_U8SecondNumber){
	error_state state;
	state=Not_okay;
	u8 result;
	if(256-Copy_U8FirstNumber>Copy_U8SecondNumber)
			state=okay;
		else
			state=Overflow;
	result=Copy_U8FirstNumber+Copy_U8SecondNumber;
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,result/10);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,result-((result/10)*10));
	_delay_ms(1500);
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,0);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,0);
	return state;
}

error_state CALC_U8DisplayMulti(u8 Copy_U8PortLEFT,u8 Copy_U8PortRIGHT,u8 Copy_U8FirstNumber, u8 Copy_U8SecondNumber){
	error_state state;
	state=Not_okay;
	u8 result;
	result=Copy_U8FirstNumber*Copy_U8SecondNumber;
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,result/10);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,result-((result/10)*10));
	_delay_ms(1500);
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,0);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,0);
	state=okay;
	return state;
}


error_state CALC_U8DisplaySubs(u8 Copy_U8PortLEFT,u8 Copy_U8PortRIGHT,u8 Copy_U8FirstNumber, u8 Copy_U8SecondNumber){
	error_state state;
	state=Not_okay;
	u8 result;
	if(Copy_U8FirstNumber>Copy_U8SecondNumber)
	result=Copy_U8FirstNumber-Copy_U8SecondNumber;
	else
	result=Copy_U8SecondNumber-Copy_U8FirstNumber;

	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,result/10);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,result-((result/10)*10));
	_delay_ms(1500);
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,0);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,0);
	state=okay;
	return state;
}
error_state CALC_U8DisplayDiv(u8 Copy_U8PortLEFT,u8 Copy_U8PortRIGHT,u8 Copy_U8FirstNumber, u8 Copy_U8SecondNumber){
	error_state state;
	state=Not_okay;
	if(Copy_U8SecondNumber==0)
		state=Not_okay;
	else
		state=okay;
	u8 result;
	if(Copy_U8SecondNumber!=0){
	result=Copy_U8FirstNumber/Copy_U8SecondNumber;
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,result/10);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,result-((result/10)*10));
	_delay_ms(1500);
	sevSeg_VidDisplayNumber(Copy_U8PortLEFT,0);
	sevSeg_VidDisplayNumber(Copy_U8PortRIGHT,0);

	}
	else;
	return state;
}

