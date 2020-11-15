/**
 * @file detachTest.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 测试detach函数
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<thread>
#include<mutex>
void hello_thread()
{
    std::cout<<"Hello Thread!"<<std::endl;
}
int msum(int a, int b)
{
    int c=a+b;
    std::cout<<a<<"+"<<b<<"="<<c<<std::endl;
    return c;
}

int main()
{
    std::thread t1(hello_thread);
    std::thread t2(msum,2,3);
    t1.detach();
    t2.detach();
    //主线程代码
    std::cout<<"Main here"<<std::endl;
    return 0;
}