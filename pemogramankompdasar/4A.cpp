#include <bits/stdc++.h>
using namespace std;
int N, mat1[76][76], mat2[76][76];

bool identik() 
{
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            if(mat1[i][j] != mat2[i][j]) return false;
        }
    }
    return true;
}

bool horisontal() 
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mat1[i][j] != mat2[N-i-1][j]) return false;
        }
    }
    return true;
}
bool vertikal()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mat1[i][j] != mat2[i][N-j-1]) return false;
        }
    }
    return true;
}
bool diagonal_kiri()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mat1[i][j] != mat2[N-j-1][N-i-1]) return false;
        }
    }
    return true;
}
bool diagonal_kanan()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mat1[i][j] != mat2[j][i]) return false;
        }
    }
    return true;
}
int main() {
    cin >> N >> N;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            cin >> mat1[i][j];
        }
    }    
    cin >> N >> N;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            cin >> mat2[i][j];
        }
    }

    // vertikal, horisontal, diagonal kanan bawah, diagonal kiri bawah
    if(identik()) {
        printf("identik");
    } else if(vertikal()) {
        printf("vertikal");
    } else if(horisontal()) {
        printf("horisontal");
    } else if(diagonal_kanan()) {
        printf("diagonal kanan bawah");
    } else if(diagonal_kiri()) {
        printf("diagonal kiri bawah");
    } else {
        printf("tidak identik");
    }

}