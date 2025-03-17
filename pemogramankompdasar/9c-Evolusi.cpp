#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int N, M;
unordered_map<string, int> nameHash;
unordered_map<int, string> nameList;
vector<vector<int>> adjList;

vector<bool> visited;
vector<int> path;
bool gotTarget = false;

string evoA, evoB;

void recDFS(int node, int target)
{
    if(gotTarget) return;

    //cout << "Exploring " << nameList[node] << "...\n";

    visited[node] = true;

    // push node to path.
    path.push_back(node);

    // if node is target, we end DFS. 
    if(node == target){
        //cout << ">Tarhget have been found!!!!\n";
        gotTarget = true;
        return;
    }

    for(auto v : adjList[node])
    {
        if(!visited[v]) {
            //cout << "DFS: from " << nameList[node] << ", go to " << nameList[v] << '\n';
            recDFS(v, target);
        }
        if(gotTarget) break;
        
    }
    //cout << "All branches of " << nameList[node] << " has been explored.\n";

    // node reaches dead end? perhaps all the node's branches didnt get target..
    //just pop node from path...
    if(!gotTarget)
    {
        path.pop_back();
        //cout << nameList[node] << " popped from path!\n";
    }
}

int main()
{
    cin >> N >> M;
    adjList.resize(N + 1);
    visited.resize(N + 1, false);
    // setup nameHash to get the hash through the species name,
    // and nameList to access the names from the nameHash.
    int currHash = 1;
    for(int i = 0; i < M; i++)
    {
        string parent, child;
        cin >> parent;
        if(nameHash[parent] == 0){
            nameHash[parent] = currHash;
            nameList[nameHash[parent]] = parent;
            currHash++;
        }
        cin >> child;
        if(nameHash[child] == 0){
            nameHash[child] = currHash;
            nameList[nameHash[child]] = child;
            currHash++;
        }
        // Use the hashes to make adjacency list
        adjList[nameHash[parent]].push_back(nameHash[child]);
    }
    //input A, B
    cin >> evoA >> evoB;
    
    //Its time to DFS.....

    //try DFS from A -> B
    recDFS(nameHash[evoA], nameHash[evoB]);
    if(!gotTarget){
        //didnt get target? reset visited nodes, and try DFS from B -> A
        fill(visited.begin(), visited.end(), false);
        recDFS(nameHash[evoB], nameHash[evoA]);
    }
    if(!gotTarget)
    {
        // still didnt get target???? tough luck.
        cout << "TIDAK MUNGKIN";
    } else {
        // we got the good shit :)
        for(auto v : path)
        {
            cout << nameList[v] << '\n';
        }
    }
    
    
    return 0;
}