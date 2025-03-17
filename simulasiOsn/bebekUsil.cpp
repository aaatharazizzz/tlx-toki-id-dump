#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int a[1001];

void printk(const int &a, const int &b)
{
    cout << "? " << a << " " << b << '\n' << flush;
}

int main()
{
    cin >> N;
    int sel;
    printk(1, 2);
    cin >> sel;
    a[0] = 1 + sel;
    a[1] = 1;
    printk(2, N);
    cin >> sel;
    int rightMax = sel + 1;
    for(int i = 2; i < N; i++)
    {
        if(i == a[0])
        {
            a[i] = rightMax;
        } else {
            a[i] = i;
        }
    }
    cout << "! ";
    for(int i = 0; i < N; i++)
    {
        cout << a[i] << ' ';
    }
    cout << flush;

    return 0;
}

/*
bekerja fi perusahaan penAmbangan mata uang  cypt
memiliki cabang di setiap N kote sunda empire

*/