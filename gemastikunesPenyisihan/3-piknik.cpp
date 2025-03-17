#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;

int n, m;
vector<int> friendlist[105];
bool friend_visited[105];
vector<int> cluster_sizes;

int main() {
    fill_n(friend_visited, 105, false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friendlist[x].push_back(y);
        friendlist[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(friend_visited[i]) {
            continue;
        }
        int count = 1;
        friend_visited[i] = true;
        deque<int> count_queue;
        count_queue.push_back(i);
        while(!count_queue.empty()) {
            for(int node : friendlist[count_queue.front()]) {
                if(!friend_visited[node]){
                    count_queue.push_back(node);
                    friend_visited[node] = true;
                    count++;
                }
            }
            count_queue.pop_front();
        }
        cluster_sizes.push_back(count);
    }
    int singles = 0;
    for(int n : cluster_sizes) {
        if(n == 1) {
            singles++;
        }
    }
    if(singles > 1) {
        printf("%d", cluster_sizes.size() - singles + 1);
    } else {
        printf("%d", cluster_sizes.size() - singles);
    }
}