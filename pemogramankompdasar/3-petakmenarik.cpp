#include <bits/stdc++.h>

std::array<int, 2> petakMenarik(std::vector<std::vector<int>> &petak, int k){
    int isize = petak.size();
    int jsize = petak[0].size();
    
    for(int j = 0; j < jsize; j++)
    {
        for(int i = 0; i < isize; i++)
        {
            int temp_k = 1;
            if(i - 1 >= 0)
                temp_k *= petak[i - 1][j];
            if(i + 1 < isize)
                temp_k *= petak[i + 1][j];
            if(j - 1 >= 0)
                temp_k *= petak[i][j - 1];
            if(j + 1 < jsize)
                temp_k *= petak[i][j + 1];
            if(temp_k == k) {
                return {i+1, j+1};
            }
        }
        std::cout << '\n';
    }
    return {0,0};
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> petak(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int buf;
            std::cin >> buf;
            petak[i].push_back(buf);
            //std::cout << 
        }
    }

    std::array<int, 2> menarik = petakMenarik(petak, k);
    std::cout << menarik[0] << ' ' << menarik[1];
    return 0;
}