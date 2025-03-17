#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<int> tinggi_suara;

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> M >> N;
        vector<int> split;
        split.reserve(N);
        int avg_size = M/N;
        int rem = M%N;
        int sum = 0;
        for(int i = 0; i < N - rem; i++) {
            split.push_back(avg_size);
            sum += avg_size;
        }
        for(int i = avg_size * N; i < M; i++) {
            split.push_back(avg_size + 1);
            sum += avg_size + 1;
        }
        for(int i = 0; i < split.size(); i++) {
            cout << split[i] << '\n';
        }
        cout << "sum is" << sum << '\n';
    }
}


// 21 c
// 22  c
// 24 b
// 26 b
// 26  b
// 28  a
// 500 a
// 211 a



