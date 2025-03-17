#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int kpk = 1;
    for(int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        kpk = std::lcm(kpk, num);
    }
    std::cout << kpk;
    return 0;
}
