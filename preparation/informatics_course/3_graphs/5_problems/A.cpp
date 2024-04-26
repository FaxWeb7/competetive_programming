#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

vi fordBellman(vector<vector<ii>> &g, int start){
    vi dist(g.size(), INF);
    queue<int> q;
    vector<bool> inQue(g.size());

    dist[start] = 0;
    q.push(start);
    inQue[start] = true;

    while (!q.empty()){
        int v = q.front();
        q.pop();
        inQue[v] = false;

        for (auto &[to, weight] : g[v]){
            if (dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                if (!inQue[to]){
                    q.push(to);
                    inQue[to] = true;
                }
            }
        }
    }

    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--, b--;
        g[a].push_back({ b, weight });
    }

    vi dist = fordBellman(g, 0);
    for (int i : dist){
        cout << (i == INF ? 30000 : i) << ' ';
    }

    return 0;
}