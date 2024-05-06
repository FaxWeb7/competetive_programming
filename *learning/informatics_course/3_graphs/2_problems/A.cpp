#include <iostream>
#include <vector>

using namespace std;

int countVertexes(vector<vector<int>>& graph, int vertex, vector<int>& visited, int counter=1){
    visited[vertex] = 1;
    for (int to : graph[vertex]){
        if (!visited[to]){
            counter = countVertexes(graph, to, visited, counter+1);
        }
    }
    return counter;
}

int main(){
    int n, s;
    cin >> n >> s;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            if (t != 0){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<int> visited(n*n);
    cout << countVertexes(graph, s-1, visited);

    return 0;
}