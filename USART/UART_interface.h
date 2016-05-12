///////////////////////////////////////////////////////////
/////////////////// MACROS ///////////////////////////////
/////////////////////////////////////////////////////////

// USCRA
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

// USCRB
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

//USCRC
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UART_HIGH 1
#define UART_LOW  0

//number of data bits
#define UART_5_DATABIT 5
#define UART_6_DATABIT 6
#define UART_7_DATABIT 7
#define UART_8_DATABIT 8
#define UART_9_DATABIT 9
//parity
#define UART_EvenPrity 2
#define UART_OddPrity 3

////////////Global Functions Prototypings ////////

void USART_Init(void );
void USART_Transmit( u16 Copy_u8Transdata ) ;
void USART_Receive( u16 *Copy_RecieveData );
///////////////////////////////////////////////////

