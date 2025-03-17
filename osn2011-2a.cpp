#include <bits/stdc++.h>

int main(){
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i % 2 == 0 && j % 2 == 0)
            {
                std::cout << "#";
            } else if(i % 2 != 0 && j % 2 != 0)
            {
                std::cout << "*";
            } else {
                std::cout << "$";
            }
        }
        std::cout << '\n';
    }
    return 0;
}