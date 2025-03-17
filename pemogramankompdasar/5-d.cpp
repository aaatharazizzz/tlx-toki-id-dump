#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, x[100010], Q, y;
int main() {
    cin >> N;
    x[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> x[i];
        x[i] += x[i-1];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> y;
        cout << distance(x, lower_bound(x+1, x+N+1, y)) << '\n';

    }
}