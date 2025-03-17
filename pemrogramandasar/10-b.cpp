#include <bits/stdc++.h>

//2 baris

int main()
{
    std::vector<int> bola[2];
    int n;
    std::cin >> n;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int a;
            std::cin >> a;
            bola[i].push_back(a);
        }
    }
    
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        char a, b;
        int x, y;
        std::cin >> a >> x >> b >> y;
        a -= 'A';
        b -= 'A';
        std::swap(bola[a][x-1], bola[b][y-1]);
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << bola[i][j];
            if(j + 1 < n) std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}