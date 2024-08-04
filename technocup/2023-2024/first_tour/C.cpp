#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

int bfs(vvi &g, int start){
    vi dist(g.size(), INF);
    queue<pii> q;

    dist[start] = 0;
    q.push({start, 1});

    int ans = 1;
    while(!q.empty()){
        pii v = q.front();
        q.pop();

        for (int &to : g[v.F]){
            if (dist[to] == INF){
                dist[to] = dist[v.F] + 1;
                q.push({to, 1-v.S});
                if (v.S == 0) ans++;
            }
        }
    }

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    vvi g(n);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int start; cin >> start;
    start--;

    cout << bfs(g, start);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}