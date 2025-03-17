#include <bits/stdc++.h>

bool sortsizes (const std::string &a, const std::string &b) { 
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    int n;
    std::vector<std::string> nama;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string buf;
        std::cin >> buf;
        nama.push_back(buf);
    }
    std::sort(nama.begin(), nama.end(), sortsizes);
    for(int i = 0; i < nama.size(); i++)
    {
        std::cout << nama[i] << '\n';
    }
    return 0;
}