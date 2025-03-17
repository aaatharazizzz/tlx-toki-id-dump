#include <bits/stdc++.h>

bool bisaHapusSatu(const std::string &a, const std::string &b)
{
    if(b.size() != a.size() - 1) return false;
    bool foundMissing = false;
    for(int i = 0; i < b.size(); i++)
    {
        if(!foundMissing)
        {
            if(a[i] != b[i]){
                foundMissing = true;
            }
        } else {
            if(a[i+1] != b[i]) return false;
        }
    }
    return true;
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    std::cout << (bisaHapusSatu(a, b) ? "Tentu saja bisa!" : "Wah, tidak bisa :(");
    return 0;
}