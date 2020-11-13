/**
 * @file classThread.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 在类内部创建线程,类内部函数为静态函数
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<mutex>
#include<thread>

class HelloThread{
    public:
    static void hello_thread(){
        std::cout<<"Hello World, I'm a thread!"<<std::endl;
    }
    static void start(){
        std::thread thrd(hello_thread);
        thrd.join();
    }
};
int main()
{
    HelloThread::start();
    return 0;
}