#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> bebek;
    for(int i = 0; i < n; i++)
    {
        int ans = 1;
        std::string tmp;
        std::cin >> tmp;
        bebek.push_back(tmp);
        for(int j = 0; j < i; j++)
        {
            if(bebek[i] > bebek[j]) ans++;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
/*
int main()
{
    int n;
    std::vector<std::string> bebek;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::vector<std::string>::iterator it; 
        std::string input;
        std::cin >> input;
        bebek.push_back(input);
        std::sort(bebek.begin(), bebek.end());
        it = std::lower_bound(bebek.begin(), bebek.end(), input);
        if(it != bebek.end()){
            std::cout << it - bebek.begin() + 1 << '\n';
        }
    }
    return 0;
}
*/