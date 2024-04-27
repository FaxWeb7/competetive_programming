#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 2009000999;

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
    int c;
    cin >> c;

    for (int l = 0; l < c; l++){
        int n, m;
        cin >> n >> m;

        vector<vector<ii>> g(n);
        for (int i = 0; i < m; i++){
            int a, b, weight;
            cin >> a >> b >> weight;
            g[a].push_back({ b, weight });
            g[b].push_back({ a, weight });
        }

        int start;
        cin >> start;

        vi dist = dijkstra(g, start);
        for (int i = 0; i < n; i++){
            cout << dist[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}