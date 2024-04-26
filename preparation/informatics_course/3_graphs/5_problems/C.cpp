#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = -1E9;

void fordBellman(vector<vector<ii>> &g, int start, int finish){
    vi dist(g.size(), INF);
    queue<int> q;
    vi inQ(g.size(), 0);

    dist[start] = 0;
    q.push(start);
    inQ[start] = 1;

    int cnt = 0;
    while (!q.empty() && cnt < g.size()){
        int v = q.front();
        q.pop();
        inQ[v] = 0;

        for (auto &[to, weight] : g[v]){
            if (dist[to] < dist[v] + weight){
                dist[to] = dist[v] + weight;
                if (!inQ[to]){
                    q.push(to);
                    inQ[to] = 1;
                }
            }
        }
        cnt++;
    }

    if (dist[finish] == INF) {
        cout << ":(";
        return;
    }

    bool hasCycle = false;
    for (int v = 0; v < g.size(); v++){
        for (auto &[to, weight] : g[v]){
            if (dist[to] != INF && dist[to] < dist[v] + weight){
                hasCycle = true;
            }
        }
    }

    if (hasCycle){
        cout << ":)";
        return;
    }

    cout << dist[finish];
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<ii>> g(n);
    for (int i = 0; i < m; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        a--, b--;
        g[a].push_back({ b, weight });
    }

    fordBellman(g, 0, g.size()-1);

    return 0;
}