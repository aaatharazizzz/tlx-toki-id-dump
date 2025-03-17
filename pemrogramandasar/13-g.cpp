#include <iostream>
#include <cmath>

int boardX, boardY, count;
int board[25][25];
bool visited[25][25] = {false};

void countFlood(int x, int y, int id);

int main()
{
    std::cin >> boardX >> boardY;
    for(int x = 0; x < boardX; x++)
    {
        for(int y = 0; y < boardY; y++)
        {
            std::cin >> board[x][y];
        }
    }
    int selX, selY;
    std::cin >> selX >> selY;
    int id = board[selX][selY];
    countFlood(selX, selY, id);
    std::cout << count * (count - 1);
    return 0;
}

void countFlood(int x, int y, int id)
{
    if((x >= 0 && x < boardX) && (y >= 0 && y < boardY))
    {
        if(!visited[x][y] && board[x][y] == id)
        {
            visited[x][y] = true;
            countFlood(x-1, y, id);
            countFlood(x+1, y, id);
            countFlood(x, y-1, id);
            countFlood(x, y+1, id);
            count++;
        }
    }
}