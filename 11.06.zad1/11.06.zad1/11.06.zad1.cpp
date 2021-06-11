// 11.06.zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"PriceCatalog.h"

int main()
{
    PriceCatalog<char> cat;
    PriceTag<char> tag('b', 23);
    std::cin >> tag;
    std::cout << tag;

    
    
}

