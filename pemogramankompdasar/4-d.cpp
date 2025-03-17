#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using ll = long long;

int move_amount;    //N
int range_size;  //R
int extra_score;    //Y
int judge_amount;   //J

std::vector<int> score_list;
std::pair<int, char> moves[11];
bool used[11];

void FillScoreList (int total_score = 0, int level = 0, char prev_movement = 'N') {
    if(level >= range_size) {
        score_list.push_back(total_score);
    } else {
        for(int i = 0; i < move_amount; i++) {
            if(used[i]) continue;
            used[i] = true;
            int score = moves[i].first;
            if(prev_movement == 'P') {
                score *= 2; 
            }
            if(prev_movement == 'L') {
                score /= 2;
            }
            if(prev_movement == 'Y') {
                score += extra_score * (range_size - level);
            }
            FillScoreList(total_score + score, level + 1, moves[i].second);
            used[i] = false;
        }
    }
}

int main() {
    int minimum_judge_scores[100001];

    std::string useless_text;
    std::getline(std::cin, useless_text);
    std::cin >> move_amount >> range_size >> extra_score >> judge_amount;
    for(int i = 0; i < move_amount; i++) {
        std::cin >> moves[i].first >> moves[i].second;
    }
    for(int i = 0; i < judge_amount; i++) {
        std::cin >> minimum_judge_scores[i];
    }

    FillScoreList();
    std::sort(score_list.begin(), score_list.end());

    for(int i = 0; i < judge_amount; i++) {
        std::vector<int>::iterator upbound;
        upbound = std::upper_bound(score_list.begin(), score_list.end(), minimum_judge_scores[i]);
        std::cout << score_list.size() - (upbound - score_list.begin()) << '\n';
    }
    return 0;
}