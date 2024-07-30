#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

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

void dfs(vector<vector<int>> &graph, int v, vector<int>& visited, vi& a, int &minV){
    visited[v] = 1;
    for (int to : graph[v]){
        minV = min(minV, a[to]);
        if (!visited[to]){
            dfs(graph, to, visited, a, minV);
        }
    }
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    
    vvi g(n);
    for (int i = 0; i < n-1; ++i){
        int pi; cin >> pi;
        g[pi-1].pb(i+1);
    }

    // for (int i = 0; i < n; ++i){
    //     cout << i << ": ";
    //     for (int j = 0; j < g[i].size(); ++j) cout << g[i][j] << ' ';
    //     cout << '\n';
    // }

    int ans = a[0];
    for (int &v : g[0]){
        if (!g[v].size()) continue;
        vi visited(n);
        int minV = INF;
        dfs(g, v, visited, a, minV);

        int cur;
        if (a[v] < minV) cur = a[v] + (minV - a[v] - 1);
        else cur = minV;
        ans = max(ans, a[0]+cur);
    }
    vi visited(n);
    int minV = INF;
    dfs(g, 0, visited, a, minV);

    int cur;
    if (a[0] < minV) cur = a[0] + (minV - a[0]);
    else cur = minV;
    ans = max(ans, a[0]+cur);

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}