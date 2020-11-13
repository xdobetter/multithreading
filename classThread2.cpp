
/**
 * @file classThread2.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 非常普通的类，只是用多线程调用其内部的函数
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<mutex>
#include<thread>
#include<functional>
class HelloWorld
{
public:
void hello(int year){
    std::cout<<"I am "<<year<<" years old"<<std::endl;
}
};
int main(int argc,char *argv[])
{
 HelloWorld obj;
 HelloWorld obj2;
 std::thread thrd(std::bind(&HelloWorld::hello,&obj,26));
 std::thread thrd2(std::bind(&HelloWorld::hello,&obj2,35));
 thrd.join();
 std::cout<<"Hello World!"<<std::endl;
 thrd2.join();
 return 0;
}