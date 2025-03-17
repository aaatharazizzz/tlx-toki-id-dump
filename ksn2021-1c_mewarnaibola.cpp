#include <bits/stdc++.h>

int printKeluaran(int a, int b){
    std::cout << "? " << a << " " << b << "\n" << std::flush;
    int input;
    std::cin >> input;
    return input;
}

int main()
{
    int t;
    int n, q;
    std::cin >> t >> n >> q;
    std::vector<int> a;
    if(t == 1 || t == 2){
        //bahan sama mempunyai bola berurutan
        int cnt = 1;
        a.push_back(cnt);
        for(int i = 2; i <= n; i++){
            if(printKeluaran(i-1, i) == 2) cnt++;
            a.push_back(cnt);
        }
    } else if (t == 3) {
        
    } else if (t == 5) {
        //N-1 BAHAN BERBEDA
        if(printKeluaran(1, n) == n - 1)
        {
            int last = 0, first = 0;
            for(int i = 1; i <= n; i++)
            {
                if(printKeluaran(1, i) < i)
                {
                    last = i; break;
                }
            }
            for(int i = n; i >= 1; i--)
            {
                if(printKeluaran(i, n) < n - i + 1)
                {
                    first = i; break;
                }
            }
            int cnt = 1;
            for(int i = 1; i <= n; i++)
            {
                if(i == last)
                {
                    a.push_back(first);
                } else {
                    a.push_back(cnt);
                    cnt++;
                }
            }
        } else {
            for(int i = 1; i <= n; i++)
            {
                a.push_back(i);
            }
        }
    }

    std::cout << "!";
    for(int i = 0; i < (int) a.size(); i++)
    {
        std::cout << " " << a[i];
    }
    std::cout << "\n" << std::flush;
    return 0;
}
