#include <bits/stdc++.h>

struct Daftar
{
    std::string nama;
    int s1, s2, s3;
};

bool compareDaftar(const Daftar& d1, const Daftar& d2)
{
    //prioirity
    //sesi 3
    if(d1.s3 != d2.s3) return d1.s3 > d2.s3;
    //sesi 2
    if(d1.s2 != d2.s2) return d1.s2 > d2.s2;
    //sesi 1
    return d1.s1 > d2.s1;
}

int main()
{
    int t, m, n;
    std::string namaPeserta;
    std::vector<Daftar> peserta;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> n >> m;
        std::cin >> namaPeserta;
        for(int j = 0; j < n; j++)
        {
            Daftar buf;
            std::cin >> buf.nama >> buf.s1 >> buf.s2 >> buf.s3;
            peserta.push_back(buf);
        }
        std::sort(peserta.begin(), peserta.end(), &compareDaftar);
        bool found = false;
        for(int k = 0; k < m; k++)
        {
            if(peserta[k].nama == namaPeserta){
                found = true;
                break;
            }
        }
        if(found){
            std::cout << "YA\n";
        }else{
            std::cout << "TIDAK\n";
        }
        peserta.clear();
    }
    return 0;
}