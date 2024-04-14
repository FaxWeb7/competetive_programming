#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

void dfs(vector<vi>& graph, int vertex, vi& visited, bool& hasCycle, vi& order){
    visited[vertex] = 1;
    for (int to : graph[vertex]){
        if (visited[to] == 0){
            dfs(graph, to, visited, hasCycle, order);
        } else if (visited[to] == 1){
            hasCycle = true;
        }
    }
    order.push_back(vertex);
    visited[vertex] = 2;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }

    vi visited(n);
    bool hasCycle = false;
    vi order;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(graph, i, visited, hasCycle, order);
        }
    }

    if (hasCycle){
        cout << "No";
    } else {
        reverse(order.begin(), order.end());
        cout << "Yes" << endl;
        for (int i : order){
            cout << i+1 << " ";
        }
    }

    return 0;
}