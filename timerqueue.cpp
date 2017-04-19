#include "timerqueue.h"
//#include <sys/time.h>
Timerqueue::Timerqueue()
{

}
Timerqueue::~Timerqueue()
{

}

void Timerqueue::add(Timer* timer)
{
    assert(timer!=nullptr);
    Timervector.push_back(timer);
}

void Timerqueue::handelontime()
{
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t seconds = tv.tv_sec;
    uint64_t now=seconds * 1000*1000 + tv.tv_usec;

    //printf("now=%ld\n",now);
    for(auto iter=Timervector.begin();iter!=Timervector.end();)
    {
        uint64_t  n=(now-(*iter)->gettime());
        
        
        if ((*iter)->isrunevery()) {
            //是一直运行的
            (*iter)->run();
            iter++;
        }
        //不是一直运行的
        else if(n>0)  //还没到时间
        {
           
            (*iter)->settime(now);
            iter++;
            
        }
        else          //到时间了
        {
            printf("now=%ld,itertime=%ld,n=%ld\n",now,(*iter)->gettime(),n);
            (*iter)->run();
            Timervector.erase(iter);
            
        }
        
        
    }
     
}