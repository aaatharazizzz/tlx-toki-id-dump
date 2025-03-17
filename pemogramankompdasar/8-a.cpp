#include <deque>
#include <iostream>

int main()
{
    std::deque<int> deq;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string buf;
        int pushVal;
        std::cin >> buf;
        if(buf == "push_back"){
            std::cin >> pushVal;
            deq.push_back(pushVal);

        } else if(buf == "push_front") {
            std::cin >> pushVal;
            deq.push_front(pushVal);

        } else if(buf == "pop_back") {
            deq.pop_back();

        } else if(buf == "pop_front"){
            deq.pop_front();
            
        }
    }
    for(auto v : deq)
    {
        std::cout << v << '\n';
    }
}