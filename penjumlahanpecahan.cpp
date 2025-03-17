#include <bits/stdc++.h>

int main()
{
    long long a1, a2, b1, b2;
    long long e, f;
    std::cin >> a1 >> a2 >> b1 >> b2;
    e = (a1 * b2) + (b1 * a2);
    f = a2 * b2;
    std::cout << e / std::gcd(e,f) << " " << f / std::gcd(e,f);
    return 0;
}

/*
old code
int a1, a2, b1, b2;
    long long e, f;
    std::cin >> a1 >> a2 >> b1 >> b2;
    e = (a1 * b2) + (b1 * a2);
    f = a2 * b2;
    std::cout << e / std::gcd(e,f) << " " << f / std::gcd(e,f);
    return 0;
*/