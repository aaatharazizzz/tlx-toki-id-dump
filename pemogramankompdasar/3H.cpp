#include <bits/stdc++.h>

bool compare(std::pair<double, double> &a, std::pair<double, double> &b)
{
    return a.second / a.first > b.second / b.first;
}

double uangMax(const std::vector<std::pair<double, double>> &wc, int x)
{
    int n = wc.size();
    double res = 0;
    for(int i = 0; i < n; i++)
    {
        if(x >= wc[i].first){
            res += wc[i].second;
        } else if(x > 0){
            res += (double)x * (wc[i].second / wc[i].first);
        } else {
            break;
        }
        x -= wc[i].first;
    }
    return res;
}

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<std::pair<double, double>> wc(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> wc[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> wc[i].second;
    }
    std::sort(wc.begin(), wc.end(), compare);
    std::cout << std::fixed << std::setprecision(5) << uangMax(wc, x);
    
    return 0;
}