#include <bits/stdc++.h>

char board[25][25] = {0};
int M, N;
bool counted[25][25] = {0};

int FloodFillCount(int x, int y, char target) {
    if(x < 0 || y < 0 || x >= N || y >= M) return 0;
    if(board[y][x] != target) return 0;
    if(counted[y][x]) return 0;
    counted[y][x] = true;
    return
        FloodFillCount(x-1, y, target) +
        FloodFillCount(x, y-1, target) +
        FloodFillCount(x+1, y, target) +
        FloodFillCount(x, y+1, target) + 1;
}

void FloodFill(int x, int y, char target) {
    if(x < 0 || y < 0 || x >= N || y >= M) return;
    if(board[y][x] != target) return;
    board[y][x] = '.';
    FloodFill(x-1, y, target);
    FloodFill(x, y-1, target);
    FloodFill(x+1, y, target);
    FloodFill(x, y+1, target);
    
}

int main() {
    std::cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }

    int max_count = 0;
    int max_x = 0;
    int max_y = 0;
    for(int y = 0; y < M; y++) {
        for(int x = 0; x < N; x++) {
            int fill_count = FloodFillCount(x, y, board[y][x]);
            if(max_count < fill_count) {
                max_count = fill_count;
                max_x = x;
                max_y = y;
            }
        }
    }
    FloodFill(max_x, max_y, board[max_y][max_x]);
    for(int x = 0; x < N; x++) {
        int drop_y = -1;
        for(int y = M-1; y >= 0; y--) {
            if(drop_y > -1 && board[y][x] != '.') {
                board[drop_y][x] = board[y][x];
                board[y][x] = '.';
                drop_y--;
            }
            if(drop_y == -1 && board[y][x] == '.') {
                drop_y = y;
            }
        }
    }

    for(int y = 0; y < M; y++) {
        for(int x = 0; x < N; x++) {
            printf("%c ", board[y][x]);
        }
        printf("\n");
    }
}