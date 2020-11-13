/**
 * @file dateSyns.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 数据同步（线程同时操作一个数据的安全性）
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<mutex>
#include<thread>
std::mutex mt;
int data=1;
void addmethod(int a)
{
    mt.lock();
    data+=a;
    std::cout<<"addmethod data= "<<data<<std::endl;
    mt.unlock();
}
void multi(int a)
{
    mt.lock();
    data*=a;
    std::cout<<"multi data= "<<data<<std::endl;
    mt.unlock();
}
int main()
{
    std::thread t1(addmethod,2);
    t1.join();
    std::thread t2(multi,10);
    
    t2.join();
    return 0;
}