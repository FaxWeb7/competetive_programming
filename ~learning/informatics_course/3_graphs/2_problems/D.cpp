#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int vertex, int color, vector<int>& visited, bool& isBipartite, vector<int>& fstBip) {
    visited[vertex] = color;
    if (color == 1) fstBip.push_back(vertex+1);
    for (int to : graph[vertex]){
        if (!visited[to]){
            dfs(graph, to, 3-color, visited, isBipartite, fstBip);
        } else if (color == visited[to]) {
            isBipartite = false;
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

    vector<int> visited(n);
    vector<int> fstBip;
    bool isBipartite = true;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(graph, i, 1, visited, isBipartite, fstBip);
        }
    }

    if (!isBipartite) cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < fstBip.size(); i++){
            cout << fstBip[i] << " ";
        }
    }

    return 0;
}