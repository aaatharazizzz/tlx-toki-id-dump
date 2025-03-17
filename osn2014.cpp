#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> range;
string shortened = "";

int N, Q;
int main()
{
    string subsoal;
    string str;
    cin >> subsoal;
    cin >> N >> Q;
    cin >> str;
    for(int i = 0; i < N; i++)
    {
        if(i == N-1 || str[i] != str[i+1])
        {
            range.push_back(i+1);
            shortened.push_back(str[i]);
        }
    }
    
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        auto low = lower_bound(range.begin(), range.end(), l);
        auto up = lower_bound(range.begin(), range.end(), r);
        int size = (up - low) + 1;
        cout << size << ' ';
        if(size < 10) {
            for(int i=low-range.begin(); i<=up-range.begin(); i++) {
                cout << shortened[i];
            }
        }
        cout << '\n';
    }
    
}