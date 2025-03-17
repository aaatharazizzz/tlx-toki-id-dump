#include <bits/stdc++.h>

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << std::lcm(a, b)/a + std::lcm(a,b)/b;
    
    return 0;
}