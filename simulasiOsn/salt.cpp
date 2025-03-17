#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N; int M;
int p[200005]; int a[200005];
bool fed[200005];
bool visitedParent[200005];
//ada N kucing di nomori 1 - N
//kucing i = anak dari kucin
int main()
{
    memset(visitedParent, false, sizeof(visitedParent));
    memset(fed, false, sizeof(fed));
    cin >> N >> M;
    p[1] = 1;
    for(int i = 2; i <= N; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> a[i];
    }
    vector<int> poopyPeople;
    
    for(int i = 1; i <= M; i++)
    {
        if(!fed[a[i]] )
        {
            fed[a[i]] = true;
        } else {
            int parent = p[i];
            int maxIdx = parent;
            bool found = false;
            while(visitedParent[parent] == false)
            {
                visitedParent[parent] = true;
                maxIdx = max(maxIdx, parent);
                if(fed[parent] == false){
                    fed[parent] = true;
                    found = true;
                    break;
                }
                parent = p[i];
            }
            if (!found)
            {
                poopyPeople.push_back(i);
            }
            memset(visitedParent, false, (maxIdx + 1));
        }
    }
    cout << poopyPeople.size() << '\n';
    for(auto i : poopyPeople)
    {
        cout << i << ' ';
    }
    return 0;
}