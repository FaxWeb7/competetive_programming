#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

void dfs(vector<vi>& graph, int i, int j, int n, int m){
    graph[i][j] = 0;
    if (i < n-1 && graph[i+1][j]){
        dfs(graph, i+1, j, n, m);
    }
    if (i > 0 && graph[i-1][j]){
        dfs(graph, i-1, j, n, m);
    }
    if (j < m-1 && graph[i][j+1]){
        dfs(graph, i, j+1, n, m);
    }
    if (j > 0 && graph[i][j-1]){
        dfs(graph, i, j-1, n, m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> graph(m, vi(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char symbol;
            cin >> symbol;
            if (symbol == '#') {
                graph[i][j] = 1;
            }
        }
    }

    int res = 0;
    vi visited(m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j]){
                dfs(graph, i, j, n, m);
                res++;
            }
        }
    }

    cout << res;

    return 0;
}

