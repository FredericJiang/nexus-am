#include <am.h>
#include <benchmark.h>
#include <limits.h>
#include <klib-macros.h>
#include <amtest.h>
#include <amdev.h>
#include <nutshell.h>
#include <fft1024.h>
#include <fft_data.h>
#include <fft_test.h>






// //64-bits reg to vector reg
// void load_data(uint64_t data_in[],int num){ 
//    int i;
//    uint64_t data1;
//    uint64_t data0;
//    uint64_t out1,out0;
//    for(i=0;i<(num/4);i++)
//    { 
//      data0 =data_in[2*i];
//      data1 =data_in[2*i+1];

//      __asm__ volatile(
 
//     " ld t0,%0\n\t\
//       ld t1,%1\n\t\
//       .word 0x0053002b"
//      :
//      :"m"(data0),"m"(data1)
//      :
//     );

//    }
  

//    __asm__ volatile(
 
//     ".word 0x0000702b"
//      :
//      :
//      :
//     );
// }



// void output_data(uint64_t data_in[],int num){ 
//    int i;
//    uint64_t data1;
//    uint64_t data0;
//    uint64_t out1,out0;
//    for(i=0;i<(num/4);i++)
//    {
//      data0 =data_in[2*i];
//      data1 =data_in[2*i+1];

//      __asm__ volatile(
 
//     " ld t0,%0\n\t\
//       ld t1,%1"
//      :
//      :"m"(data0),"m"(data1)
//      :
//     );
//     __asm__ volatile(
 
//     " sd t0,%0\n\t\
//       sd t1,%1"
//      :"=m"(out0),"=m"(out1)
//      :
//      :
//     );
// };

// }
