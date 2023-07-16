#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#define HIGH 1
#define LOW 0

#define PORTA_REG *((u8*)0x3B)
#define PORTB_REG *((u8*)0x38)
#define PORTC_REG *((u8*)0x35)
#define PORTD_REG *((u8*)0x32)

#define DDRA_REG        *((u8*)0x3A)
#define DDRB_REG        *((u8*)0x37)
#define DDRC_REG        *((u8*)0x34)
#define DDRD_REG        *((u8*)0x31)

#define PINA_REG *((volatile u8*)0x39)
#define PINB_REG *((volatile u8*)0x36)
#define PINC_REG *((volatile u8*)0x33)
#define PIND_REG *((volatile u8*)0x30)
#define A 0
#define B 1
#define C 2
#define D 3



#endif