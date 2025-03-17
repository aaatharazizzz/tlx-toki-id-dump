#include <iostream>
#include <cmath>

std::string biner(int n)
{
    if(n == 1) return "1";
    if(n%2 == 1) return biner(n/2) + "1";
    return biner(n/2) + "0";
}

int main()
{
    int n;
    std::cin >> n;
    std::cout <<biner(n);
    return 0;
}