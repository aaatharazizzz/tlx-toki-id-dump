#include <iostream>
#include <cmath>

bool palindrom(std::string s)
{   
    if(s.length() <= 1) return true;
    std::string sub = s.substr(1, s.length() - 2);
    return(s[0] == s[s.length() - 1]) && palindrom(sub);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << (palindrom(s) ? "YA" : "BUKAN");
    return 0;
}