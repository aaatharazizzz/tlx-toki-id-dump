#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll M;
int N;
struct Pelat {
    int i;
    ll h;
};
Pelat p[11];

bool compPelat(Pelat &p1, Pelat &p2) {
    return p1.h < p2.h || p1.i > p2.i;
}

void push_first_digits(int digits[50], int *cursor, int n) {
    if(*cursor >= 50) return;
    digits[*cursor] = n;
    *cursor++;
}

void push_last_digits(int digits[50], int *cursor, int n) {
    digits[*cursor] = n;
    *cursor++;
    *cursor %= 50;
}

int main() {
    cin >> N;
    for(int i = 0; i <= N; i++) {
        p[i].i = i;
        cin >> p[i].h;
    }
    sort(p, p + N + 1, compPelat);
    int first_digits[50], last_digits[50];
    int first_digits_cursor = 0;
    int last_digits_cursor = 0;
    ll digit_size = 0;
    fill_n(first_digits, 50, -1);
    fill_n(last_digits, 50, -1);
    if(p[0].i == 0) {
        
    }
}