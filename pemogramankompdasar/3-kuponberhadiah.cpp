#include <bits/stdc++.h>

int main()
{
    std::vector<int> kupon;
    int n, menang;
    std::cin >> n >> menang;
    for(int i = 0; i < n; i++)
    {
        int buf;
        std::cin >> buf;
        kupon.push_back(buf);
    }
    std::sort(kupon.begin(), kupon.end());
    int j_kecil = abs(menang - kupon[0]);
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(j_kecil > abs(menang - kupon[i]))
        {
            j_kecil = abs(menang - kupon[i]);
            idx = i;
        }
    }
    std::cout << kupon[idx];
    return 0;
}
