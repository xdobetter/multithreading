/**
 * @file NodataSyns.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 多个线程同时对同一变量进行操作的时候，如果不对变量做一些保护处理，有可能导致处理结果异常：
 * 有两个问题，一是有很多变量被重复输出了，而有的变量没有被输出；
 * 二是正常情况下每个线程输出的数据后应该紧跟一个换行符，但这里大部分却是另一个线程的输出。
 * 这是由于第一个线程对变量操作的过程中，第二个线程也对同一个变量进行各操作，
 * 导致第一个线程处理完后的输出有可能是线程二操作的结果。针对这种数据竞争的情况，
 * 可以使用线程互斥对象mutex保持数据同步。修改后对应的文件是dataSyns2.cpp
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<thread>
#include<stdlib.h>
int totalNum=10;
void thread01()
{
    while (totalNum>0)
    {
        std::cout<<"totalNum="<<totalNum<<std::endl;
        totalNum--;
        //_sleep(100);
    }
}

void thread02()
{
    while (totalNum>0)
    {
        std::cout<<"totalNum="<<totalNum<<std::endl;
        totalNum--;
        //_sleep(100);
    }
}
int main()
{
    std::thread task01(thread01);
    std::thread task02(thread02);
    task01.join();
    task02.join();
    for(int i=0;i<5;i++)
    {
        std::cout<<"main thread working"<<std::endl;
        //_sleep(100);
    }
    return 0;
}