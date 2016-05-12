
/////////////////////////////////////////
//////////////// USCRA///////////////////
////////////////////////////////////////

// enable or disable multi_process
//range : UART_HIGH , UART_LOW
#define  UART_u8Multi_pros  UART_LOW
// enable or disable DOUBLE data rate
//range : UART_HIGH, UART_LOW
#define  UART_u8DoublRate   UART_LOW

/////////////////////////////////////////
//////////////// USCRB ///////////////////
////////////////////////////////////////
//range: UART_LOW --> Disable  , UART_LOW--> Enable

// config the MC to work as Tx
#define UART_TXEN_INIT    UART_HIGH
// config the MC to work as Rx
#define UART_RXEN_INIT    UART_HIGH
//enable register empty interrupt
#define UART_REGEMPTYIE_INIT   UART_LOW
//enable transmission complete interrupt
#define UART_TXCOMPIE_INIT   UART_LOW
//enable receiving complete interrupt
#define UART_RXCOMPIE_INIT   UART_LOW

/////////////////////////////////////////
//////////////// USCRC ///////////////////
////////////////////////////////////////
// enable or disable mode select
//range : UART_HIGH--> sync , UART_LOW-->async
#define  UART_u8Mod_SEL  UART_LOW
// enable or disable and choose parity
//range :  UART_LOW --> disable , UART_EvenPrity ,UART_OddPrity
#define  UART_u8PARITY   UART_LOW
// number of stop bit select
//range :  UART_LOW ->  one bit ,UART_HIGH -->2 bit
#define UART_u8STOPBIT   UART_HIGH
// number of data bits/frame
//range :  5 , 6 , 7 , 8 , 9
#define UART_u8DATABITS  UART_8_DATABIT
// clock polarity
//range :  UART_HIGH--> falling , UART_LOW--rising
#define UART_u8POLARITY  UART_LOW

/////////////////////////////////////////
//////////////// UDDR ///////////////////
////////////////////////////////////////
#define FCPU 4000000
#define BAUD 9600







