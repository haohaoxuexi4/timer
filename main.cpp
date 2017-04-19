//main.cpp#

#include <stdio.h>
//#include "timer.h"
#include "timerqueue.h"
void f1()
{
    printf("1\n");
}
void f2()
{
    printf("2\n");
}
void f3()
{
    printf("3\n");
}
int main()
{
    Timerqueue timque;
    //利用for 循环 设置10个定时器  5 个运行一次，5个运行到结束
    Timerstamp time(2*1000*1000);
    for(int i=0;i<3;i++)
    {
        //Timer tim(&fn,100000*1000,false);
        //timque.add(&tim);
    }
    Timer tim(&f1,10*1000,false);
    timque.add(&tim);
    
    Timer tim1(&f2,10*1000,false);
    timque.add(&tim1);
    
    Timer tim2(&f3,10*1000,false);
    timque.add(&tim2);
    while (1) {
        //sleep(1);
        timque.handelontime();
        
    }
   // timque.handelontime();
    //printf("helloworld\n");
    return 0;
}