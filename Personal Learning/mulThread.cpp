/**
 * @file mulThread.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 多线程测试
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>
using namespace std;

//线程要做的事情就写在这个线程函数中
void GetSumT(vector<int>::iterator first, vector<int>::iterator last, int &result)
{
    result = accumulate(first, last, 0); //调用C++标准库算法
}

int main() //主线程
{
    int result1, result2, result3, result4, result5;
    vector<int> largeArrays;
    for (int i = 0; i < 100000000; i++)
    {
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }
    thread first(GetSumT, largeArrays.begin(),
                 largeArrays.begin() + 20000000, std::ref(result1)); //子线程1
                
    thread second(GetSumT, largeArrays.begin() + 20000000,
                  largeArrays.begin() + 40000000, std::ref(result2)); //子线程2
                  
    thread third(GetSumT, largeArrays.begin() + 40000000,
                 largeArrays.begin() + 60000000, std::ref(result3)); //子线程3
                 
    thread fouth(GetSumT, largeArrays.begin() + 60000000,
                 largeArrays.begin() + 80000000, std::ref(result4)); //子线程4

                
    thread fifth(GetSumT, largeArrays.begin() + 80000000,
                 largeArrays.end(), std::ref(result5)); //子线程5

    first.detach(); //主线程要等待子线程执行完毕
    std::cout<<"result1="<<result1<<endl;
    second.join();
    std::cout<<"result2="<<result2<<endl;
    third.join();
    std::cout<<"result3="<<result3<<endl;
    fouth.join();
    std::cout<<"result4="<<result4<<endl;
    fifth.join();
 std::cout<<"result5="<<result5<<endl;
    int resultSum = result1 + result2 + result3 + result4 + result5; //汇总各个子线程的结果
    
    
    
   
   
    std::cout<<"resultSum"<<resultSum<<endl;
    return 0;
}