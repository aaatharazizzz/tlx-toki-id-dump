#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> kaki(n), sepatu(m);
    for(int i = 0; i < n; i++)
    {
        std::cin >> kaki[i];
    }
    for(int i = 0; i < m; i++)
    {
        std::cin >> sepatu[i];
    }
    std::sort(kaki.begin(), kaki.end());
    std::sort(sepatu.begin(), sepatu.end());
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(kaki[i] == sepatu[j] || kaki[i]+1 == sepatu[j])
            {
                total++;
                sepatu[j] = -1; //essentially getting rid of the shoe. the duck's feet shouldn't be negative. 
                break;
            }
        }
    }
    std::cout << total;

    return 0;
}