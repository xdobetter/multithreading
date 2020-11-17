/**
 * @file ArgFun.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 有参多线程
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 *
 */
#include<thread>
#include<iostream>
//#include<mutex>
int msum(int a,int b){
    int c=a+b;
    std::cout<<a<<"+"<<b<<"="<<c<<std::endl;
    return c;
}
int main()
{
    std::thread t1(msum,1,2);

    //主线程等待子线程运行结束后方可执行下一步
    t1.join();

    //主线程代码

    std::cout<<"Main here"<<std::endl;
    return 0;
}