#include <iostream>
#include <string>

int main()
{
    std::string str;
    unsigned int offset;
    std::cin >> str >> offset;
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = (str[i] - 'a' + offset) % 26 + 'a';
    }

    std::cout << str;

    return 0;
}