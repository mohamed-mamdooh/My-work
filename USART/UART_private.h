

//typedef unsigned char uint8;

#define BAUDRATE ((FCPU)/(BAUD*16UL)-1)

#define UART_UBRRH *((volatile u8*)(0x40))
#define UART_UCSRC *((volatile u8*)(0x40))
#define UART_UCSRA *((volatile u8*)(0x2B))
#define UART_UCSRB *((volatile u8*)(0x2A))
#define UART_UBRRL *((volatile u8*)(0x29))
#define UART_UDR   *((volatile u8*)(0x2C))



#if (UART_u8DATABITS==5)
#define UCSZ0_INIT 0
#define UCSZ1_INIT 0
#define UCSZ2_INIT 0

#elif (UART_u8DATABITS==6)
#define UCSZ0_INIT 1
#define UCSZ1_INIT 0
#define UCSZ2_INIT 0

#elif (UART_u8DATABITS==7)
#define UCSZ0_INIT 0
#define UCSZ1_INIT 1
#define UCSZ2_INIT 0

#elif (UART_u8DATABITS==8)
#define UCSZ0_INIT 1
#define UCSZ1_INIT 1
#define UCSZ2_INIT 0

#elif (UART_u8DATABITS==9)
#define UCSZ0_INIT 1
#define UCSZ1_INIT 1
#define UCSZ2_INIT 1

#endif

#if (UART_u8PARITY==UART_LOW)
#define UPM0_INIT 0
#define UPM1_INIT 0
#elif (UART_u8PARITY==UART_EvenPrity)
#define UPM0_INIT 0
#define UPM1_INIT 1
#elif (UART_u8PARITY==UART_OddPrity)
#define UPM0_INIT 1
#define UPM1_INIT 1
#endif


#define UART_TXB8_INIT    UART_LOW
#define UART_RXB8_INIT    UART_LOW

#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define UCSRC_u8INIT conc(UART_u8POLARITY,UCSZ0_INIT,UCSZ1_INIT,UART_u8STOPBIT,UPM0_INIT,UPM1_INIT,UART_u8Mod_SEL ,1 )
#define UCSRB_u8INIT conc(UART_TXB8_INIT,UART_RXB8_INIT,UCSZ2_INIT,UART_TXEN_INIT,UART_RXEN_INIT,UART_REGEMPTYIE_INIT, UART_TXEN_INIT ,UART_RXEN_INIT )
#define UCSRBA_u8INIT conc(UART_u8Multi_pros,UART_u8DoublRate,0,0,0,0,0,0)



