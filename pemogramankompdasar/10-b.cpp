#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int> akik;
    for(int i = 0; i < n; i++)
    {
        int buf;
        cin >> buf;
        switch (buf)
        {
        case 1:
            int a;
            cin >> a;
            akik.push(a);
            break;
        case 2:
            cout << akik.top() << '\n';
            break;
        case 3:
            akik.pop();
            break;
        default:
            break;
        }
    }
    return 0;
}