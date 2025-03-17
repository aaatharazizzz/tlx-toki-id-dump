#include <iostream>
#include <string>

long long fucktorial(long long n)
{
    if(n == 1) return 1;
    if(n % 2 == 0){
        return n/2 * fucktorial(n-1);
    } else {
        return n * fucktorial(n-1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << fucktorial(n);
    return 0;
}