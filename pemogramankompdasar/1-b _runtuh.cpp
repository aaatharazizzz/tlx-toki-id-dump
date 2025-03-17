#include <bits/stdc++.h>
using namespace std;

int R, C;

int main()
{
    char board[20][8];
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
    
    while(true)
    {
        int lowestFilled = -1;
        for(int i = 0; i < R; i++)
        {
            bool filledRow = true;
            for(int j = 0; j < C; j++)
            {
                if(board[i][j] == '0') filledRow = false;
            }
            if(filledRow)
            {
                for(int j = 0; j < C; j++)
                {
                    board[i][j] = '0';
                }
                lowestFilled = max(lowestFilled, i);
            }
        }
        if(lowestFilled == -1) 
        {
            break;
        } 
        else 
        {
            for(int j = 0; j < C; j++) 
            {
                for(int i = R-1; i >= 0; i--) 
                {
                    if(board[i][j] == '1' && i < lowestFilled) {
                        int bottom = R - 1;
                        for(int k = i + 1; k < R; k++ ) {
                            if(board[k][j] == '1') {
                                bottom = k - 1;
                                break;
                            }
                        }
                        board[i][j] = '0';
                        board[bottom][j] = '1';
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < R; i++) 
    {
        for(int j = 0; j < C; j++) 
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}