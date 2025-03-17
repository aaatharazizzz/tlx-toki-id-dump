#include <bits/stdc++.h>
#define ll long long
using namespace std;

int M;
struct Job {
    int s;
    int e;
    ll p;
};
bool job_sorter(Job lhs, Job rhs) { 
    if(lhs.s != rhs.s) return lhs.s < rhs.s; 
    if(lhs.e != rhs.e) return lhs.e < rhs.e;
    return lhs.p < rhs.p;
}
Job job[10001];

int main() {
    cin >> M;
    int emax = 0;
    job[0] = {0, 0, 0};
    for(int i = 1; i <= M; i++) {
        cin >> job[i].s >> job[i].e >> job[i].p;
        emax = max(emax, job[i].e);
    }
    ll dp[2][15050];
    fill_n(dp[0], sizeof(dp[0])/ sizeof(ll), 0);
    fill_n(dp[1], sizeof(dp[1])/ sizeof(ll), 0);
    for(int i = 1; i <= M; i++) {
        int iprev = i % 2;
        int inow = 1 - (i%2);
        for(int t = 1; t <= emax; t++) {
            ll best = dp[iprev][t];
            if(t == job[i].e) {
                best = max(best, job[i].p + dp[iprev][job[i].s-1]);
            }
            dp[inow][t] = best;
        }
    }
    cout << dp[1-M%2][emax];
}