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
    int n, start, finish;
    cin >> n >> start >> finish;
    start--, finish--;

    vector<vector<ii>> g(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int weight;
            cin >> weight;
            if (weight != -1 && i != j){
                g[i].push_back({ j, weight });
            }
        }
    }

    vi dist = dijkstra(g, start);
    cout << (dist[finish] == INF ? -1 : dist[finish]);

    return 0;
}