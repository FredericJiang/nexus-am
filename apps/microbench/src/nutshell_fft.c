/*这个程序最多512个点，如果需要处理更多的数据，可以改动R的值*/
#include <am.h>
#include <benchmark.h>
#include <limits.h>
#include <klib-macros.h>
#include <amtest.h>
#include <amdev.h>
#include <nutshell.h>

#define   R   2048
#define   PI   3
typedef struct
     {
      uint16_t   real;
      uint16_t   img;
      }complex;
complex   x[R], W[R];
void fft(); 
void change();

uint16_t   N=1024;
uint16_t   L=10;

void   add(complex   a,complex   b,complex   *c)   //复数加法
           {   
             c->real=a.real+b.real;   
             c->img=a.img+b.img;   
            }   
    
 void   mul(complex   a,complex   b,complex   *c)   //复数乘法
             {   
               c->real=a.real*b.real   -   a.img*b.img;   
               c->img=a.real*b.img   +   a.img*b.real;   
              }   
 void   sub(complex   a,complex   b,complex   *c)   //复数减法
              {   
                c->real=a.real-b.real;   
                c->img=a.img-b.img;   
               }   

void   change()   //序列的倒序
           {   
				complex   temp;  
				int i=0,j=0,k=0;
				for(i=0;i<N-1;i++)		//最后一个序列不需要交换，只需要循环N-1次
                {                   
					k=N/2;
					if(j>i)				//不相等时变换序列
						{   
							temp=x[i];   
							x[i]=x[j];   
							x[j]=temp;   
						}  
					while(k<=j)			//k是N/2，比K大则j最高位是1
                       {   
							j=j-k;		//j-k=j-N/2就是把j最高位清0
							k=k/2;		//比较次高位					
                        } 
				  j=j+k;				//0时置1
                   
                   }   
               }

void   fft()   
{   
    uint16_t   a,i=0,j=0,k=0,l=0;   
    complex   HI,LO,OU;   //定义奇偶两部分和结果的复数结构
    //change();   //倒序列
	for(a=0;a<N;a++)   
	{   
      W[a].real=2*PI/N*a;   //指数从0到N-1的所有旋转因子
	  W[a].img=-1*PI/N*a;
	}   
	 for(i=0;i<L;i++)
      {       
        l=1<<i;   //最外层循环，每循环一次左移一位，即*2，控制旋转因子的数量
        for(j=0;j<N;j+= 2*l   )//在第L级中，同一个旋转因子对应间隔为2的L次方的蝶形,N 是63
          {                           
            for(k=0;k<l;k++)
               {                 
                 mul(x[j+k+l],W[N*k/2/l],&OU);  //一次蝶形运算的过程 
                 add(x[j+k],OU,&HI);   
                 sub(x[j+k],OU,&LO); 
                 x[j+k]=HI;   x[j+k+l]=LO;
             }   
        }   
} }




int main()
{                 
uint32_t start =uptime();
fft(); 
uint32_t end =uptime();
printf("1024-points-FFT execution baseline time is %d ms\n",end-start);
printf("Total number of running instructions on baseline program is 204014 \n");
//return 0;            
while(1);
}

