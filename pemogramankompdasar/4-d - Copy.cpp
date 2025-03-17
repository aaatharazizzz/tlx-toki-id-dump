#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main() {
    int move_amount = 5;
    int select_amount = 2;
    bool selected_move[move_amount] = { false };
    std::fill(selected_move.begin(), selected_move.begin() + select_amount, true);
    
    do {
        for(auto v : selected_move) {
            if(v == true) printf("1 ");
            if(v == false) printf("0 ");
        }
    } while(std::next_permutation(selected_move.begin(), selected_move.end()));

}
