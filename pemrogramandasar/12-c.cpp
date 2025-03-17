#include <iostream>
#include <cmath>
int a, b;
int f(int k, int x)
{
    if(k == 0) return x;
    return f(k-1, abs(a * x + b));
}

int main()
{
    int k, x;
    std::cin >> a >> b >> k >> x;
    std::cout << f(k, x);
    return 0;
}