#include <bits/stdc++.h>

struct Waktu{
    int start;
    int duration;
};

bool compEnd(Waktu &a, Waktu &b){
    return a.start + a.duration < b.start + b.duration;
}

int aktivitasMax(std::vector<Waktu> jadwal)
{
    std::sort(jadwal.begin(), jadwal.end(), compEnd);
    int last_end = 0;
    int count = 0;
    for(int i = 0; i < jadwal.size(); i++)
    {
        if(last_end <= jadwal[i].start)
        {
            last_end = jadwal[i].start + jadwal[i].duration;
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<Waktu> jadwal;
    
    for(int i = 0; i < n; i++)
    {
        Waktu temp;
        std::cin >> temp.start >> temp.duration;
        jadwal.push_back(temp);
    }

    std::cout << aktivitasMax(jadwal);
    
    return 0;
}