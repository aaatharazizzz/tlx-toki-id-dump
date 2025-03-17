#include <iostream>
using namespace std;
typedef long long ll;

ll n, l;
ll b[100003];
ll pcs[100003];
ll pcs_size = 1;


int main() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    pcs[0] = l;
    for(int i = 0; i < n; i++) {
        pcs[b[i]-1] /= 2;
        pcs_size += 1;
        for(int j = pcs_size-1; j >= b[i]; j--) {
            pcs[j] = pcs[j-1];
        }
    }
    for(int i = 0; i < pcs_size; i++) {
        printf("%lld ", pcs[i]);
    }
}