#include <bits/stdc++.h>
using namespace std;
long long ans;
long long n, sDengklek, sMusuh;
long long p[300010], k[300010], l[300010];


int main()
{
    std::priority_queue<long long, vector<long long>, greater<long long>> pq;
    std::string s;
    std::cin >> s;
    std::cin >> n >> sDengklek >> sMusuh;
    for(int i = 0; i < n - 1; i++)
    {
        std::cin >> p[i] >> k[i] >> l[i];
    }
    long long total = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(sDengklek < p[i])
        {
            if(p[i] - sDengklek > pq.size())
            {
                std::cout << -1;
                return 0;
            } else{
                for(int j = 0; j < p[i] - sDengklek; j++)
                {
                    total += pq.top();
                    sDengklek++;
                    pq.pop();
                }
            }
        }
        if(k[i] < l[i])
        {
            total += k[i];
            pq.push(l[i] - k[i]);
        }else{
            total += l[i];
            sDengklek++;
        }
    }

    
    if(sDengklek < sMusuh){
        if(sMusuh - sDengklek > pq.size()){
            total = -1;
        } else{
            for(int i = 0; i < sMusuh-sDengklek; i++)
            {
                total += pq.top();
                pq.pop();
            }
        }
    }

    std::cout << total;
    
    return 0;
}