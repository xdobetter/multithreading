/**
 * @file SingletonThread.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 在Singleton模式内部创建线程
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <thread>
#include <mutex>
#include<algorithm>
#include<functional>
class HelloWorld
{
public:
    void hello()
    {
        std::cout << "Hello World,I'm a thread!" << std::endl;
    }
    static void start()
    {
        std::thread thrd(std::bind(&HelloWorld::hello,&HelloWorld::getInstance()));
        thrd.join();
    }
    static HelloWorld &getInstance()
    {
        if(!instance) instance=new HelloWorld;
        return *instance;
    }

private:
    HelloWorld() {}
    static HelloWorld *instance;
};
HelloWorld *HelloWorld::instance=0;
int main(int argc,char* argv[]){
    HelloWorld::start();
    return 0;
}