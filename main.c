/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/*********************File: main.c*********************/
/******************Date: 8th Sep 2022******************/
/*********************Version: V1**********************/
/***************Desc:main source file******************/
/******************************************************/
/******************************************************/


#include <avr/delay.h>
#include"STD_TYPES.h"
#include"Error_state.h"
#include "Calc_interface.h"



u8 main(void){
u8 x,y,count,Arrange,Another,Number,value;
DIO_VidSetPortDirection(2,0);
DIO_VidSetPortDirection(0,0xFF);
DIO_VidSetPortValue(2,0xFF);

DIO_VidSetPortDirection(1,0b00000111);
DIO_VidSetPortValue(1,0b00000111);

Another=0;
while(1){
	if(Another==0){
		u8 val4;
	for(u8 i=0;i<8;i++){
		DIO_VidGetPinValue(2,i,&val4);
	if(val4==1){
		x=i+1;
		Arrange=i;
		Another++;
		Number=x;
		break;}
	else x=0;
		}}
	else if(Another==1) {
		u8 val5;
		for(u8 i=0;i<8;i++){
			DIO_VidGetPinValue(2,i,&val5);
			if(val5==1 && i!=Arrange)
				{y=i+1;Arrange=i;Another=2;Number=y;break;}
			else
				y=0;
				}
	}else;


if(Another==1){
	DIO_VidSetPortDirection(3,0xFF);
		sevSeg_VidDisplayNumber(3,Number);
}

if(Another==2){
	DIO_VidSetPortDirection(3,0xFF);
		sevSeg_VidDisplayNumber(3,Number);
		Another++;
}


u8 val1=5;u8 val2=5;u8 val3=5;

DIO_VidGetPinValue(1,0,&val1);
if(val1==0)
	CALC_U8DisplaySum(3,0,x,y);
DIO_VidGetPinValue(1,1,&val2);
if(val2==0)
	CALC_U8DisplaySubs(3,0,x,y);
DIO_VidGetPinValue(1,2,&val3);
if(val3==0)
	CALC_U8DisplayMulti(3,0,x,y);

//	CALC_U8DisplayDiv(3,0,x,y);

}
	return 0;

}

