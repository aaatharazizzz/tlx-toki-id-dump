#include <bits/stdc++.h>

int main()
{
    int n;
    std::vector<int> arr;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int buf;
        std::cin >> buf;
        arr.push_back(buf);
    }
    for(int i = n-1; i >= 0; i--)
    {
        std::cout << arr[i] << (i > 0 ? "," : "");
    }

    return 0;
}