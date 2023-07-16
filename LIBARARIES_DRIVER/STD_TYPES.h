#include<stdio.h>
#ifndef STD_TYPES_H
#define STD_TYPES_H
typedef signed char s8 ;
typedef unsigned char u8 ;
typedef signed  short int s16 ;
typedef unsigned  short int u16 ;
typedef signed  long int s32 ;
typedef unsigned  long int u32 ;
typedef signed  long long int s64 ;
typedef unsigned  long long int u64 ;
typedef float f32 ;
typedef double f64 ;
typedef long double f128 ;

/*define Ports*/
#define A       0
#define B       1
#define C       2
#define D       3

/*define Pins*/
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

/*define logic voltages*/
#define HIGH 1
#define LOW 0

#endif
