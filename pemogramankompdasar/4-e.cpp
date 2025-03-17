#include <iostream>
#include <cmath>

int boardX, boardY, count;
int board[25][25];
bool visited[25][25] = {false};

void countFlood(int x, int y, int id, int &counter);

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

    int maxcounter = 0;
    for(int x = 0; x < boardX; x++)
    {
        for(int y = 0; y < boardY; y++)
        {
            int counter = 0;
            countFlood(x, y, board[x][y], counter);
            if(counter > maxcounter) maxcounter = counter;
        }
    }
    std::cout << maxcounter * (maxcounter - 1);
    return 0;
}

void countFlood(int x, int y, int id, int &counter)
{
    if((x >= 0 && x < boardX) && (y >= 0 && y < boardY))
    {
        if(!visited[x][y] && board[x][y] == id)
        {
            visited[x][y] = true;
            countFlood(x-1, y, id, counter);
            countFlood(x+1, y, id, counter);
            countFlood(x, y-1, id, counter);
            countFlood(x, y+1, id, counter);
            counter++;
        }
    }
}