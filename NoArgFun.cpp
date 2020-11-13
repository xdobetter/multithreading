/**
 * @file NoArgFun.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 无参多线程函数
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<thread>
#include<iostream>
#include<mutex>
void hello_thread()
{
    std::cout<<"Hello thread"<<std::endl;
}
int main()
{
    std::thread t1(hello_thread);

    //主线程等待子线程运行结束后方可执行下一步
    t1.join();
    //主线程代码
    std::cout<<"Main here"<<std::endl;
    return 0;
}