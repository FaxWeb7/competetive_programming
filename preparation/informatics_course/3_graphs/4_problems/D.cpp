#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

struct Edge {
    int weight;
    int idx;
    int limit;
    Edge (int weight, int idx, int limit) : weight(weight), idx(idx), limit(limit) {};
};

vi dijkstra(vector<vector<Edge>> &g, Edge start){
    vi dist(g.size(), INF);
    set<Edge> q;

    dist[start.idx] = 0;
    q.insert(Edge(start.weight, start.idx, start.limit));

    while (!q.empty()){
        auto nearest = q.begin();
        q.erase(q.begin());

        for (auto &[weight, idx, limit] : g[nearest->idx]){
            if (dist[idx] > dist[nearest->idx] + weight && (limit - 3E6)/100 >= (nearest->limit - 3E6)/100){
                q.erase({ dist[idx], idx, limit });
                dist[idx] = dist[nearest->idx] + weight;
                q.insert({ dist[idx], idx, limit });
            }
        }
    }

    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    Edge start = {-1,-1,-1};
    for (int i = 0; i < m; i++){
        int a, b, weight, limit;
        cin >> a >> b >> weight >> limit;
        a--, b--;
        if (i == 0) start = {weight, b, limit};
        g[a].push_back({ weight, b, limit });
        g[b].push_back({ weight, a, limit });
    }

    vi dist = dijkstra(g, start);
    cout << dist[n-1];

    return 0;
}