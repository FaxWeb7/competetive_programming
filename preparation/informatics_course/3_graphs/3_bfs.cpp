#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1E9;

vector<int> getPath(vector<int>& from, int finish){
    // функция для восстановления кратчайшего пути из 0 в finish
    vector<int> path;
    for (int v = finish; v != -1; v = from[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

pair<vector<int>, vector<int>> bfs(vector<vector<int>>& graph, int start){
    vector<int> dist(graph.size(), INF);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (int to : graph[v]){
            if (dist[to] > dist[v] + 1){ //if dist[to] == INF
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    return { dist, from };
}