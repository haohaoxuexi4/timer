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
    
    Timer tim(&f1,0,false);
    timque.add(tim);
    
    //sleep(1);
    Timer tim1(&f2,1*1000,true);
    timque.add(tim1);
    
    //sleep(5);
    Timer tim2(&f3,3*1000,false);
    timque.add(tim2);
    
    while (1) {
        timque.handelontime();
    }
    
    
    
   // timque.handelontime();
    //printf("helloworld\n");
    return 0;
}