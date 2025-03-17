#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

ll n;
ll pascal[29][29];
ll pascalsum_rl[29*29];

int main() {
    cin >> n;
    n--;
    if(n == 0) {
        printf("%lld", 1073741823);
        return 0;
    }
    double maxlog10 = 0;
    for(int i = 0; i < 29; i++) {
        for(int j = 0; j < 29; j++) {
            if(i == 0 || j == 0) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j] + pascal[i][j-1];
            }
            maxlog10 = max(maxlog10, log10(pascal[i][j]));
        }
    }
    for(int i = 0; i < 29; i++) {
        for(int j = 0; j < 29; j++) {
            pascalsum_rl[i*29+j] = pascal[i][28-j] + ((i*29+j) > 0 ? pascalsum_rl[i*29+j-1] : 0);
        }
    }
    
    ll max_pascal_sum_y = (lower_bound(pascalsum_rl, pascalsum_rl+29*29, n) - pascalsum_rl)/29;
    ll mut_n = n;
    ll bits = 0;
    for(int sel_y = max_pascal_sum_y; sel_y >= 0; sel_y--) {
        ll sum_idx = lower_bound(pascalsum_rl, pascalsum_rl+29*29, mut_n) - pascalsum_rl;
        ll sum_idx_y = sum_idx / 29;
        ll sum_idx_x = sum_idx % 29;
        bits |= 1 << (29 - sum_idx_x + sel_y);
        if(sel_y > 0) {
            mut_n = mut_n - (mut_n - pascalsum_rl[(sel_y-1)*29 + 28]);
        }
    }
    cout << bitset<64>(bits);
    return 0;
}