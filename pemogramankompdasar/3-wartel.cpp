#include <bits/stdc++.h>

int main()
{
    std::vector<std::string> nama;
    std::vector<std::string> nomor;
    int n, q;
    std::cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        std::string nm, no;
        std::cin >> nm >> no;
        nama.push_back(nm);
        nomor.push_back(no);
    }
    for(int i = 0; i < q; i++)
    {
        std::string carinama;
        std::cin >> carinama;
        
        if(!std::binary_search(nama.begin(), nama.end(), carinama)){
            std::cout << "NIHIL\n";
        } else{
            std::cout << nomor[std::lower_bound(nama.begin(), nama.end(), carinama)-nama.begin()] << '\n';
        }
    }
    return 0;
}