/**
 * @file mulThread2.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 简单多线程demo，该demo反映了两个并行的线程执行次序每次不一，且join函数会阻塞主线程，所以子线程
 * 都执行完后才执行主线程，可以使用detach将子线程从主流程中分离，独立运行，不会阻塞主线程
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<thread>
#include<stdlib.h>
void thread01()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<"Thread 01 is working!"<<std::endl;
        //_sleep(100);
    }
}
void thread02()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<"Thread 02 is working!"<<std::endl;
        //_sleep(200);
    }
}
int main()
{
    std::thread task01(thread01);
    std::thread task02(thread02);
    task01.join();
    task02.join();

    //main thread work
    for(int i=0;i<5;i++)
    {
        std::cout<<"main thread working!"<<std::endl;
    }
    return 0;
}