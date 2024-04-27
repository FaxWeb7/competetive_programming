#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

vi dijkstra(vector<vector<ii>> &g, int start){
    vi dist(g.size(), INF);
    set<ii> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()){
        int nearest = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, weight] : g[nearest]){
            if (dist[to] > dist[nearest] + weight){
                q.erase({ dist[to], to });
                dist[to] = dist[nearest] + weight;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

int main(){
    int n;
    cin >> n;
    vi cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];

    int m;
    cin >> m;
    vector<vector<ii>> g(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back({ b, cost[a] });
        g[b].push_back({ a, cost[b] });
    }

    vi dist = dijkstra(g, 0);
    if (dist[n-1] == INF) cout << -1;
    else cout << dist[n-1];

    return 0;
}