/**
 * @file SingleThread.cpp
 * @author dobetter (db.xi@zju.edu.cn)
 * @brief 单线程测试
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/**
 * @brief Get the Sum object
 * 
 * @param first 
 * @param last 
 * @return int 
 */
int GetSum(vector<int>::iterator first, vector<int>::iterator last)
{
    return accumulate(first, last, 0);
}
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
    std::thread t(largeArrays.begin(), largeArrays.end()));
    vector<int> largeArrays;
    for (int i = 0; i < 10000000; i++)
    {
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }
    int res = GetSum(largeArrays.begin(), largeArrays.end());
    std::cout << "输出求和: " << res << endl;
    return 0;
}