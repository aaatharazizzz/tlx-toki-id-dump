#include <bits/stdc++.h>

int main()
{
    std::deque<int> deq;
    int n;
    std::cin >> n;
    //bikin bool reversed agar ga perlu bikin fungsi reverse yg bikin TLE,
    //ini deque broo, bisa push back, push front, pop back, dan pop front!!
    bool reversed = false;
    for(int i = 0; i < n; i++)
    {
        int pushVal, amount;
        std::string buf;
        std::cin >> buf;
        if(buf == "add"){
            std::cin >> pushVal >> amount;
            for(int i = 0; i < amount; i++)
            {
                reversed ? deq.push_front(pushVal) : deq.push_back(pushVal);
            }
            std::cout << deq.size() << '\n';

        } else if(buf == "del") {
            std::cin >> amount;
            int removedVal = reversed ? deq.back() : deq.front();
            for(int i = 0; i < amount; i++)
            {
                reversed ? deq.pop_back() : deq.pop_front();
            }
            std::cout << removedVal << '\n';

        } else if(buf == "rev") {
            reversed ? reversed = false : reversed = true;
        }
    }
    
    return 0;
}