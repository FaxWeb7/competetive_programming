#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

vi dijkstra(vector<vector<ii>> &graph, int start){
    vi dist(graph.size(), INF);
    set<ii> q;

    dist[start] = 0;
    q.insert({ dist[start], start }); 
    // q[i].first обязательно должно быть именно расстояние от А до Б, тк set в первую очередь сортирует по первому ключу

    while(!q.empty()){
        int nearest = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, weight] : graph[nearest]){
            if (dist[to] > dist[nearest] + weight) {
                q.erase({ dist[to], to });
                dist[to] = dist[nearest] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

int main(){
    int n, m, start;
    cin >> n >> m;

    vector<vector<ii>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        a--; b--;
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    cin >> start;

    return 0;
}