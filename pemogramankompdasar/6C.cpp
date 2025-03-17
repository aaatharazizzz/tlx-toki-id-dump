#include <bits/stdc++.h>

long long getScalar(const std::vector<int> &v1, const std::vector<int> &v2, const int &n){
    long long res = 0;
    for(int i = 0; i < n; i++)
    {
        res += (long long)v1[i] * (long long)v2[i];
    }
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v1, v2;
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        v1.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        v2.push_back(temp);
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end(), std::greater<int>());
    std::cout << getScalar(v1, v2, n);
    return 0;
}