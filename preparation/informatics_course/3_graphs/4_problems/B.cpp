#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

void printPath(vi &from, int finish){
    vi path;
    for (int v = finish; v != -1; v = from[v]){
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    for (int n : path) cout << n+1 << ' ';
}

pair<vi, vi> dijkstra(vector<vector<ii>> &g, int start) {
    vi dist(g.size(), INF);
    vi from(g.size(), -1);
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
                from[to] = nearest;
                q.insert({ dist[to], to });
            }
        }
    }

    return {dist, from};
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

    auto [dist, from] = dijkstra(g, start);
    if (dist[finish] == INF){
        cout << -1;
        return 0;
    }
    printPath(from, finish);

    return 0;
}