#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <climits>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = LLONG_MAX;
const int MOD = 1e9 + 7;

vi dijkstra(vector<vector<pii>> &graph, vi &a){
    vi dist(graph.size(), INF);
    set<pii> q;

    dist[0] = a[0];
    q.insert({ dist[0], 0 });
    while (!q.empty()){
        int v = q.begin()->S;
        q.erase(q.begin());

        for (auto &[to, weight] : graph[v]){
            if (dist[to] > dist[v] + weight + a[to]){
                q.erase({dist[to], to});
                dist[to] = dist[v] + weight + a[to];
                q.insert({dist[to], to});
            }
        }
    }

    return dist;
}

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    for (int &x : a) cin >> x;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    vi dist = dijkstra(graph, a);
    for (int i = 1; i < n; ++i){
        cout << dist[i] << ' ';
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}