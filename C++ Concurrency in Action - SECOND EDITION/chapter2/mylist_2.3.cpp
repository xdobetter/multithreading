/**
 * @file mylist_2.3.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 特殊情况下的等待,使用“资源获取即初始化方式”(RAII，Resource Acquisition Is Initialization)，
 * 并且提供一个类，在析构函数中使用join()
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <thread>
#include<iostream>
class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread &t_) : t(t_) {}
    ~thread_guard()
    {
        if (t.joinable())
        {
            std::cout<<"~thread_guard()"<<std::endl;
            t.join();
        }
    }
    thread_guard(thread_guard const &) = delete;
    thread_guard &operator=(thread_guard const &) = delete;
};
void do_something(int &i)
{
    std::cout<<"i="<<i<<std::endl;
    ++i;
}
struct func
{
    int &i;
    func(int &i_) : i(i_) {}
    void operator()()
    {
        for (unsigned j = 0; j < 10000; j++)
        {
            /* code */
            do_something(i);
        }
    }
};

void do_something_in_current_thread() {}

void f()
{
    int some_local_state;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    do_something_in_current_thread();
}
int main()
{
    f();
}
