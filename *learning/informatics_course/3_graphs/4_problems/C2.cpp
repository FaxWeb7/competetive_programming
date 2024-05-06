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
    int n, m, start, finish;
    cin >> n >> start >> finish >> m;
    start--; finish--;

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; i++){
        int a, startTime, b, finishTime;
        cin >> a >> startTime >> b >> finishTime;
        a--; b--;
        g[a].push_back({ b, finishTime - startTime });
    }

    vi dist = dijkstra(g, start);
    if (dist[finish] == INF) {
        cout << -1;
        return 0;
    }
    cout << dist[finish];

    return 0;
}