#include <bits/stdc++.h>


int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    std::sort(b.begin(), b.end());
    std::cout << b[k-1];
    
    return 0;
}