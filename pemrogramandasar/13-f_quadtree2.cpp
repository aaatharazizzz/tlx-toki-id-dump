#include <bits/stdc++.h>
using namespace std;

int T;
int R, C;
bool elm[128][128];
int ansCount = 0;
vector<string> kode;

void translateToQuad(int k, int r, int c, string str)
{
    //printf("current str = %s || ", str.c_str());
    if(str.length() > 1)
    {
        char nextQuadrant = str[1];
        str.erase(1, 1);
        if(nextQuadrant == '0') {
            translateToQuad(k/2, r, c, str);
        } 
        else if(nextQuadrant == '1') {
            translateToQuad(k/2, r, c+(k/2), str);
        } 
        else if(nextQuadrant == '2') {
            translateToQuad(k/2, r+(k/2), c, str);
        } 
        else if(nextQuadrant == '3') {
            translateToQuad(k/2, r+(k/2), c+(k/2), str);
        }
    } else {
        
        if(str == "1") {
            //printf("Applying quad.. k: %d, r: %d - %d , c: %d , %d. \n", k, r, r+k, c, c+k);
            for(int i = r; i < r + k; i++)
            {
                for(int j = c; j < c + k; j++)
                {
                    elm[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    memset(elm, 0, sizeof(elm));
    int pow2 = 1;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        kode.push_back(str);
    }
    cin >> R >> C;
    int maxRc = max(R, C);
    while (pow2 < maxRc)
    {
        pow2 *= 2;
    }

    for(auto &str : kode)
    {
        translateToQuad(pow2, 0, 0, str);
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(elm[i][j] == 0) cout << "0 ";
            else cout << "1 ";
        }
        cout << '\n';
    }
    
    return 0;
}