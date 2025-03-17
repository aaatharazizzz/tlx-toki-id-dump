#include <bits/stdc++.h>

std::vector<long long> getPrimeList(long long n)
{
    std::vector<long long> list;
    bool eliminated[n + 1];
    for(long long i = 2; i <= n; i++)
    {
        if(eliminated[i] == false)
        {
            list.push_back(i);
            long long j = i * i;
            while(j <= n)
            {
                eliminated[j] = true;
                j += i;
            }
        }
    }
    return list;
}

int main()
{
    std::vector<long long> primeList = getPrimeList(1000000);
    
    unsigned int k, t;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> k;
        std::cout << primeList[k-1] << '\n';
    }
    return 0;
}
