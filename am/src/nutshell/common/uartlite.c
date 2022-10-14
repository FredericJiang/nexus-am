#include <riscv.h>


// #define UARTLITE_MMIO 0x40600000
// #define UARTLITE_RX_FIFO  0x0
// #define UARTLITE_TX_FIFO  0x4
// #define UARTLITE_STAT_REG 0x8
// #define UARTLITE_CTRL_REG 0xc

// #define UARTLITE_RST_FIFO 0x03
// #define UARTLITE_TX_FULL  0x08
// #define UARTLITE_RX_VALID 0x01

// void __am_init_uartlite(void) {
//   outb(UARTLITE_MMIO + UARTLITE_CTRL_REG, UARTLITE_RST_FIFO);
// }

//static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
// void __am_uartlite_putchar(char ch) {
//   if (ch == '\n') __am_uartlite_putchar('\r');

//   while (inb(UARTLITE_MMIO + UARTLITE_STAT_REG) & UARTLITE_TX_FULL);
//   outb(UARTLITE_MMIO + UARTLITE_TX_FIFO, ch);
// }

// int __am_uartlite_getchar() {
//   if (inb(UARTLITE_MMIO + UARTLITE_STAT_REG) & UARTLITE_RX_VALID)
//     return inb(UARTLITE_MMIO + UARTLITE_RX_FIFO);
//   return 0;
// }



#define UART_BASE       0xe0000000
#define XUARTPS_FIFO_OFFSET 0x0000000c
#define XUARTPS_SR_OFFSET 0x0000000b
#define SR_TX_FULL  0x10
#define SR_RX_EMPTY 0x02

#define UART_REG_TXFIFO		0
#define UART_REG_RXFIFO		1
#define UART_REG_TXCTRL		2
#define UART_REG_RXCTRL		3
#define UART_REG_DIV		4

#define UART_TXEN		 0x1
#define UART_RXEN		 0x1

volatile unsigned int* uart;

void __am_init_uartlite() {
  uart = (void *)UART_BASE;
  uart[UART_REG_TXCTRL] = UART_TXEN;
  uart[UART_REG_RXCTRL] = UART_RXEN;
}

void __am_uartlite_putchar(char ch) {
    volatile unsigned int *tx = uart + XUARTPS_FIFO_OFFSET;
    if (ch == '\n') __am_uartlite_putchar('\r');    
    while((*((volatile unsigned int*)(uart + XUARTPS_SR_OFFSET)) & SR_TX_FULL) != 0);
    *tx = ch;
}

// void uart_puts(char *s) {
//     int i = 0;
//     while (s[i]) {
//         if (s[i]=='\n') __am_uartlite_putchar('\r');
//     	__am_uartlite_putchar(s[i++]);
//     }
// }

// void uart_putn(int n) {
//     char buf[10], buf_r[10];
//     int offset = 0;
//     do {
//         buf[offset++] = n % 10 + '0';
//         n = n / 10;
//     } while (n);

//     for (int i = 0; i < offset; ++i)
//      { buf_r[offset-i-1] = buf[i]; buf_r[offset] = 0;}

//     uart_puts(buf_r);
// }
