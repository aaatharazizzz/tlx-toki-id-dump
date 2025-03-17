#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<int> tinggi_suara;

int main() {

    cin >> M;
    int tmp;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        tinggi_suara.push_back(tmp);
    }
    cin >> N;
    sort(tinggi_suara.begin(), tinggi_suara.end());
    vector<int> split;
    split.reserve(N);
    int avg_size = M/N;
    int rem = M%N;
    for(int i = 0; i < N - rem; i++) {
        split.push_back(avg_size);
    }
    for(int i = avg_size * N; i < M; i++) {
        split.push_back(avg_size + 1);
    }
    do {
        bool valid = true;
        int idx = 0;
        for(int i = 0; i < N - 1; i++) {
            idx += split[i];
            if(tinggi_suara[idx - 1] == tinggi_suara[idx]) {
                valid = false;
                break;
            }
        }
        if(valid) break;
    } while(next_permutation(split.begin(), split.end()));

    int idx = 0;
    for(int i = 0; i < N - 1; i++) {
        idx += split[i];
        printf("%d ", tinggi_suara[idx]);
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



