#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    ll total_days = 0;
    if(b == 0) {
        if(c == 0) {
            total_days += (a + d + 2)/3;
        } else {
            total_days += (a + c + 2)/3 + (d + 2)/3;
        }
    } else {
        if(c == 0) {
            total_days += (a+2)/3 + (b+d+2)/3;
        } else {
            total_days += (a+2)/3 + (b+c+2)/3 + (d+2)/3;
        }
    }
    printf("%lld", total_days);
}