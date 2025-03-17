#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> catat = {0};

void tulis(int kedalaman =0)
{
    if(kedalaman >= k){
        for(int i = 0; i < k; i++)
        {
            cout << catat[i] << ' ';
        }
        cout << '\n';
    } else {
        for(int i = catat[max(0, kedalaman - 1)] + 1; i <= n; i++)
        {
            catat[kedalaman] = i;
            tulis(kedalaman + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    catat.resize(k);
    tulis();
    return 0;
}