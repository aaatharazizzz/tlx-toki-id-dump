#include <bits/stdc++.h>

int main()
{ 
    std::vector<int> bebek;
    int n, b;
    std::cin >> n >> b;
    for(int i = 0; i < n; i++){
        int buf;
        std::cin >> buf;
        bebek.push_back(buf);
    }
    std::sort(bebek.begin(), bebek.end(), std::greater<int>());
    int counter = 0;
    int total = 0;
    for(int i = 0; i < bebek.size(); i++){
        total += bebek[i];
        counter++;
        if(total > b)
        {
            break;
        }
    }
    std::cout << counter;
    return 0;
}

