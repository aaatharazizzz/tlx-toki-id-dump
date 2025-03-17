#include <bits/stdc++.h>

int main()
{
    std::stack<int> stak;
    int n;
    std::cin >> n;

    int modifier = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        std::string buf;
        std::cin >> buf;
        if(buf == "add"){
            std::cin >> x >> y;
            for(int i = 0; i < y; i++)
            {
                stak.push(x - modifier);
            }
            std::cout << stak.size() << '\n';
            
        } else if(buf == "del") {
            std::cin >> y;
            std::cout << stak.top() + modifier << '\n';
            for(int i = 0; i < y; i++)
            {
                stak.pop();
            }
            
        } else if(buf == "adx") {
            std::cin >> x;
            modifier += x;
        } else if(buf == "dex") {
            std::cin >> x;
            modifier -= x;
        }
    }
    
    return 0;
}