// 11.06.prakt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"TimestampWithDescription.h"

int main()
{
    Time time;
    TimestampWithDescription desc;
    std::cin >> desc;
    std::cin >> time;
    std::cout << std::endl;
    std::cout << "time: " << time << std::endl;;
    std::cout << "Desc: " << desc;
    std::cout<<std::endl;
    std::cout << (time += 234);
}
