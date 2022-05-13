#ifndef __MAIN_H__
#define __MAIN_H__
/*************************************************
时间：2022年3月
本程序由张陈潇编写用于蓝桥杯赛前准备
*************************************************/
#include <STC15F2K60S2.H>
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define Y4 (P2&0x1f)|0x80//打开相应锁存器
#define Y5 (P2&0x1f)|0xa0
#define Y6 (P2&0x1f)|0xc0
#define Y7 (P2&0x1f)|0xe0
#define Yc (P2&0x1f)|0x00

sbit buzz = P0^6;//定义引脚
sbit realy = P0^4;

sbit S4 = P3^3;//独立按键定义
sbit S5 = P3^2;
sbit S6 = P3^1;
sbit S7 = P3^0;

sbit ha1 = P3^0;//矩阵按键定义
sbit ha2 = P3^1;
sbit ha3 = P3^2;
sbit ha4 = P3^3;
sbit li4 = P3^4;
sbit li3 = P3^5;
sbit li2 = P4^2;
sbit li1 = P4^4;
#endif