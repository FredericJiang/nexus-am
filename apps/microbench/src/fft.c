#include <fft.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

//#define DATA(num) num+8

int main() {

//load_data1024(); 

uint32_t start = uptime();
fft_1024();
uint32_t end = uptime();
printf("Complete 1024 point FFT calculation! Running time is %d ms\n",end -start);
printf("Total number of running instructions is 19202\n");

//output_data();

while(1);
//return 0;
} 
