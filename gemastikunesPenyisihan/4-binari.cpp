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
ll pascal[30][30];
ll offset[30][30];
ll pascalsum_rl[30*30];

int main() {
    cin >> n;
    n--;
    if(n == 0) {
        printf("%lld", 1073741823);
        return 0;
    }
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
            if(i == 0 || j == 0) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j] + pascal[i][j-1];
            }
        }
    }
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
            pascalsum_rl[i*30+j] = pascal[i][29-j] + ((i*30+j) > 0 ? pascalsum_rl[i*30+j-1] : 0); 
            if(j > 0) {
                offset[i][j] = offset[i][j-1] + pascal[i][29 - j];
            } else {
                offset[i][j] = ((i > 0) ? offset[i-1][29] : 1);
            }
        }
    }
    ll max_y = (lower_bound(pascalsum_rl, pascalsum_rl+30*30, n) - pascalsum_rl)/30;
    ll mut_n = n;
    ll bits = 0;
    while(mut_n > 0) {
        //printf("mutn:%lld\n", mut_n);
        ll mut_n_idx = (lower_bound(pascalsum_rl, pascalsum_rl+30*30, mut_n) - pascalsum_rl);
        ll mut_n_y = mut_n_idx / 30;
        ll mut_n_x = mut_n_idx % 30;
        bits |= ll(1) << (29 + mut_n_y - mut_n_x);
        mut_n -= offset[mut_n_y][mut_n_x];
    }
    ll mask = 1;
    mask <<= (31 + max_y);
    mask--;
    printf("%lld", ~bits & mask);
    return 0;
}