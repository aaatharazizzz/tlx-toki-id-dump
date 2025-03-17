#include <bits/stdc++.h>
using namespace std;

int R, C;
bool elm[128][128];
int ansCount = 0;
vector<string> ans;


bool homogen(int r, int c, int k)
{
    bool val = elm[r][c];
    for(int  i = r; i < r + k; i++)
    {
        for(int j = c; j < c + k; j++)
        {
            if(elm[i][j] != val) return false;
        }
    }
    return true;
}

void quadTree(int k, int r = 0, int c = 0,  string str = "")
{
    if(homogen(r, c, k) )
    {
        if(elm[r][c] == 1){
            ans.push_back('1' + str);
        }
    } else {
        quadTree(k/2, r, c, str+"0");
        quadTree(k/2, r, c+(k/2), str+"1");
        quadTree(k/2, r+(k/2), c, str+"2");
        quadTree(k/2, r+(k/2), c+(k/2), str+"3");
    }
}

int main()
{
    memset(elm, 0, sizeof(elm));
    cin >> R >> C;
    int maxSide = max(R, C);
    int pow2 = 1;
    while(pow2 < maxSide)
    {
        pow2 *= 2;
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> elm[i][j];
        }
    }
    
    quadTree(pow2, 0, 0, "");
    cout << ans.size() << '\n';
    for(auto i : ans)
    {
        cout << i << '\n';
    }


    return 0;
}