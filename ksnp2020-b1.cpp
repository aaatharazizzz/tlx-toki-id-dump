#include <bits/stdc++.h>

void solve(const std::vector<int> &a, const std::vector<int> &b){
    for(int i = 0; i < b.size(); i++)
    {
        int passed = 0;
        int total = 0;
        for(int j = 0; j < a.size(); j++)
        {
            total += a[j];
            if(b[i] >= total){
                passed++;
            } else{
                break;
            }
        }
        std::cout << passed << '\n';
    } 
}

int main()
{
    int n, k;
    std::vector<int> a1, b1;
    std::cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        int a1buf;
        std::cin >> a1buf;
        a1.push_back(a1buf);
    }
    for(int i = 0; i < k; i++)
    {
        int b1buf;
        std::cin >> b1buf;
        b1.push_back(b1buf);
    }
    solve(a1, b1);
    return 0;
}