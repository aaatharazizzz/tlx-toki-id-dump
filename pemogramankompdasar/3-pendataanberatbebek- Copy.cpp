#include <bits/stdc++.h>
/*
bool comp (const int &a, const int &b) { 
    return a <= b;
}
*/
int main()
{
    int n, q;
    std::vector<int> berat;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int buf;
        std::cin >> buf;
        berat.push_back(buf);
    }
    std::cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::vector<int>::iterator low, high;
        low  = std::upper_bound(berat.begin(), berat.end(), x);
        high = std::upper_bound(berat.begin(), berat.end(), y);
        
        std::cout << (high - berat.begin()) - (low - berat.begin()) << '\n';
    }
    return 0;
}