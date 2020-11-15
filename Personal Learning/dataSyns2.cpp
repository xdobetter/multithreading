// #include<iostream>
// #include<thread>
// #include<mutex>
// std::mutex mu;
// int totalNum=10;
// void thread01()
// {
//     for(int i=0;i<5;i++)
//     {
//         //mu.lock();
//         /* code */
//         std::cout<<"thread 01 totalNum="<<totalNum<<std::endl;
//         //totalNum--;
//         //mu.unlock();
//     }
// }
// void thread02()
// {
//     for(int i=0;i<5;i++)
//     {
//         /* code */
//         //mu.lock();
//         std::cout<<"thread 02 totalNum="<<totalNum<<std::endl;
//         //totalNum--; 
//         //mu.unlock();
//     }
// }
// int main()
// {
//     std::thread task01(thread01);
//     std::thread task02(thread02);
//     task01.join();
//     task02.join();
//     for (size_t i = 0; i < 5; i++)
//     {
//         /* code */
//         std::cout<<"main thread working! "<<std::endl;
//     }
//     return 0;
// }

#include<iostream>
#include<thread>
#include<mutex>
#include<stdlib.h>
std::mutex mu;
int totalNum=10;
void thread01(int p)
{
    for(int i=0;i<5;i++)
    {
        mu.lock();
        /* code */
        std::cout<<"thread "<<p<<" totalNum="<<totalNum<<std::endl;
        //totalNum--;
        _sleep(10000);
        mu.unlock();
    }
}
void thread02(int p)
{
    for(int i=0;i<5;i++)
    {
        /* code */
        mu.lock();
        std::cout<<"thread "<<p<<" totalNum="<<totalNum<<std::endl;
        //totalNum--; 
        _sleep(10000);
        mu.unlock();
        
    }
}
int main()
{
    std::thread task01(thread01,1);
    std::thread task02(thread02,2);
    //task02.join();
    //task01.join();
    for (size_t i = 0; i < 5; i++)
    {
        /* code */
        std::cout<<"main thread working! "<<std::endl;
    }
    return 0;
}

