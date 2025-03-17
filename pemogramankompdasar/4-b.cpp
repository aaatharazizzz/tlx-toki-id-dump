#include <bits/stdc++.h>

int n;
int skor[5] = {0};
int skorConfig[5] = {0};

bool validScores(int home = 0, int away = 1);

int main()
{
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> skor[i];
        }
        std::cout << (validScores() ? "YES" : "NO") << '\n';
    }

    return 0;
}

bool validScores(int home, int away){
    bool mungkin = false;
    if(home >= n - 1)
    {
        mungkin = true;
        for(int i = 0; i < n; i++)
        {
            if(skor[i] != skorConfig[i]) return false;
        }
    } else if(away >= n){
        return mungkin || validScores(home + 1, home + 2);
    } else {
        
        skorConfig[home] += 3;
        mungkin = mungkin || validScores(home, away + 1);
        skorConfig[home] -= 3;

        skorConfig[home] += 1;
        skorConfig[away] += 1;
        mungkin = mungkin || validScores(home, away + 1);
        skorConfig[home] -= 1;
        skorConfig[away] -= 1;

        skorConfig[away] += 3;
        mungkin = mungkin || validScores(home, away + 1);
        skorConfig[away] -= 3;

    }
    return mungkin;
}