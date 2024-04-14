#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int vertex, vector<int>& visited, int parent, bool& hasCycle){
    visited[vertex] = 1;
    for (int to : graph[vertex]){
        if (to == parent) {
            continue;
        } else if (visited[to] == 0){
            dfs(graph, to, visited, vertex, hasCycle);
        } else if (visited[to] == 1){
            hasCycle = true;
        }
    }
    visited[vertex] = 3;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int num;
            cin >> num;
            if (num) {
                graph[i].push_back(j);
            }
        }
    }

    bool isTree = true;

    vector<int> visited(n);
    bool hasCycle = false;
    dfs(graph, 0, visited, -1, hasCycle);
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            isTree = false;
        }
    }

    if (hasCycle) isTree = false;

    cout << (isTree ? "YES" : "NO");

    return 0;
}