#include <bits/stdc++.h>
using namespace std;

string s;

int dp[55][55];
int i_lookup[55];

int recdp(int l, int r, vector<int> t[]) {
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int best = 0;
    for(int i = l + 1; i < r; i++) {
        int ub = distance(t[s[i]].begin(), upper_bound(t[s[i]].begin(), t[s[i]].end(), r-1) - 1);
        int ass = 1;
        if(i < t[s[i]][ub]) ass = 2; 
        best = max(best, ass + recdp(i, t[s[i]][ub], t));
    }
    return dp[l][r] = best;
}

int main() {
    int T = 1; cin >> T;
    while(T--){
        fill_n(i_lookup, 50, 0);
        for(int i = 0; i < 50; i++) {
            fill_n(dp[i], sizeof(dp[i])/sizeof(dp[i][0]), -1);
        }
        vector<int> things[SCHAR_MAX+1];
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(!things[s[i]].empty()) continue;
            for(int j = i; j < s.size(); j++) {
                if(s[j] == s[i]) {
                    things[s[i]].push_back(j);
                    i_lookup[j] = things[s[i]].size() - 1;
                }
            }
        }
        
        int best = 0;
        for(int i = 0; i < s.size(); i++) {
            int newr = things[s[i]].back();
            int lol = 1;
            if(i < newr) lol = 2;
            best = max(best, lol + recdp(i, newr, things));
        }
        cout << best << '\n';
    }
}