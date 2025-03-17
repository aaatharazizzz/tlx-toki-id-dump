#include <bits/stdc++.h>
using namespace std;

/* 
void permutasi(int n, int kedalaman = 0)
{
    if(kedalaman >= n){
        bool zigzag = true;
        for(int i = 1; i < n-1; i++)
        {
            bool cond1 = ((catat[i] > catat[i-1]) && (catat[i] > catat[i+1]));
            bool cond2 = ((catat[i] < catat[i-1]) && (catat[i] < catat[i+1]));
            if (!(cond1 || cond2))
            {
                zigzag = false;
                break;
            }
        }

        if(zigzag)
        {
            for(int i = 0; i < n; i++)
            {
                std::cout << catat[i];
            }
            std::cout << '\n';
        }
        
    } else {
        
        for(int i = 1; i <= n; i++)
        {
            if(!pernah[i-1])
            {
                pernah[i-1] = true;
                catat[kedalaman] = i;
                permutasi(n, kedalaman + 1);
                pernah[i-1] = false;
            }
        }
    }
}
 */
int main()
{
    int n;
    cin >> n; 
    std::vector<int> catat(n);
    for(int i = 0; i < n; i++)
    {
        cin >> catat[i];
    }
    sort(catat.begin(), catat.end());
    do{
        bool foundDupe = false;
        for(int i = 0; i < n-1; i++)
        {
            if(catat[i] == catat[i + 1])
            {
                foundDupe = true;
                break;
            }
        }
        if(!foundDupe)
        {
            for(auto v : catat)
            {
                std::cout << v;
            }
            std::cout << '\n';
        }
        
    } while(std::next_permutation(catat.begin(), catat.end()));
    //permutasi(n);
    return 0;
}