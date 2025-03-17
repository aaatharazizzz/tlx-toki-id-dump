#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int n;
    std::vector<int> x, y;
    std::vector<long long> freqx(5001), freqy(5001);
    std::cin >> n;
    x.resize(n);
    y.resize(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
        freqx[x[i]]++;
        freqy[y[i]]++;
    }
    long long total = 0; 
    for(int i = 0; i < n; i++)
    {
        total += (freqx[x[i]]-1)*(freqy[y[i]]-1);
    }
    std::cout << total;
    return 0;
    
}