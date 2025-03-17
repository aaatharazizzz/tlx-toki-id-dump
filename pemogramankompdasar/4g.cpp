#include <bits/stdc++.h>
using namespace std;
int M, N;
char board[25][25];

int flood(int i, int j, char target, char board[][25]) {
    if(i < 0 || j < 0 || i == M || j == N) return 0;
    if(board[i][j] != target) return 0;
    board[i][j] = '.';
    return (
        flood(i+1, j, target, board) +
        flood(i-1, j, target, board) +
        flood(i, j+1, target, board) +
        flood(i, j-1, target, board) + 1
    );
}

void fall(char b[][25]) {
    for(int j = 0; j < N; j++) {
        int drop = -1;
        for(int i = M-1; i >= 0; i--) {
            if(drop != -1 && b[i][j] != '.') {
                b[drop][j] = b[i][j];
                b[i][j] = '.';
                drop--;
            }
            if(drop == -1 && b[i][j] == '.') {
                drop = i;
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    char b2[25][25];
    int best = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != '.') {
                memcpy(b2, board, sizeof(board));
                int count = flood(i, j, board[i][j], b2);
                if(count == 1) continue;
                int total = count * (count - 1);
                fall(b2);
                best = max(best, total);
                for(int i2 = 0; i2 < M; i2++) {
                    for(int j2 = 0; j2 < N; j2++) {
                        if(b2[i2][j2] != '.') {
                            int count2 = flood(i2, j2, b2[i2][j2], b2);
                            if(count2 == 1) continue;
                            int total2 = total + count2 * (count2 - 1);
                            best = max(best, total2);
                        }
                    }
                }
            }
        }
    }
    cout << best;

}