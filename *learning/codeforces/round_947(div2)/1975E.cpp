#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
#define int ll
const int INF = 1e9;

void dfs(vector<vi> &graph, int v, vi& visited, vi& c, int &cnt){
    cnt++;
    visited[v] = 1;

    int neighbours = 0;
    for (int to : graph[v]){
        if (c[to]) neighbours++;
        if (!visited[to] && c[to]){
            dfs(graph, to, visited, c, cnt);
        }
    }

    if (neighbours > 2) cnt = -100000;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, q; cin >> n >> q;

        vi c(n);
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<vi> graph(n);
        for (int i = 0; i < n-1; ++i){
            int a, b;
            cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        while (q--){
            int u; cin >> u;
            c[u-1] = 1-c[u-1];
            
            int expect = 0;
            for (int i = 0; i < c.size(); ++i) {
                if (c[i]) {
                    expect++;
                }
            }

            if (expect == 0){
                cout << "No\n";
            } else {
                bool ans = false;
                for (int i = 0; i < c.size(); ++i) {
                    if (c[i]) {
                        vi visited(n);
                        int cnt = 0;
                        dfs(graph, i, visited, c, cnt);
                        if (cnt == expect) {
                            ans = true;
                        }
                        break;
                    }
                }
                cout << (ans ? "Yes\n" : "No\n");
            }
        }
    }

    return 0;
}