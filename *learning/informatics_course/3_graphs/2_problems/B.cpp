#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int vertex, vector<int>& visited, vector<int>& newComponent){
    visited[vertex] = 1;
    newComponent.push_back(vertex);
    for (int to : graph[vertex]){
        if (!visited[to]){
            dfs(graph, to, visited, newComponent);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> components;

    vector<int> visited(n);
    for(int i = 0; i < n; i++){
        if (!visited[i]){
            vector<int> newComponent;
            dfs(graph, i, visited, newComponent);
            components.push_back(newComponent);
        }
    }

    cout << components.size() << endl;
    for (int i = 0; i < components.size(); i++){
        cout << components[i].size() << endl;
        for (int j = 0; j < components[i].size(); j++){
            cout << components[i][j]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}