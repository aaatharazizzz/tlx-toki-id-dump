#include <iostream>
#include <cmath>

void gambarGunung(int n)
{
    if(n > 0)
    {
        gambarGunung(n-1);
        for(int i = 0; i < n; i++){
            std::cout << '*';
        }
        std::cout << '\n';
        gambarGunung(n-1);
    }
}

int main()
{
    int n;
    std::cin >> n;
   gambarGunung(n);
    return 0;
}