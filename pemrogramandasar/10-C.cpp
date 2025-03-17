#include <bits/stdc++.h>

int reverse(const int &a)
{
    int temp = a;
    int res = 0;
    while(temp > 0)
    {
        res = (res * 10) + (temp % 10);
        temp /= 10;
    }

    return res;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << reverse(reverse(a) + reverse(b));
    return 0;
}