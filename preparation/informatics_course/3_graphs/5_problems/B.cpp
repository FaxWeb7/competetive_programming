#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

void printPath(vi &from, int start){
    vi path = { start };
    for (int v = from[start]; v != start; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    cout << path.size()+1 << '\n';
    cout << start+1 << ' ';
    for (int v : path) {
        cout << v+1 << ' ';
    }
}

void fordBellman(vector<vector<ii>> &g, int start){
    vi dist(g.size(), INF);
    vi from(g.size(), -1);
    queue<int> q;
    vector<bool> inQue(g.size());

    dist[start] = 0;
    from[start] = -1;
    q.push(start);
    inQue[start] = true;

    int cnt = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        inQue[v] = false;

        for (auto &[to, weight] : g[v]){
            if (dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                from[to] = v;
                if (!inQue[to]){
                    q.push(to);
                    inQue[to] = true;
                }
            }
        }
        if (cnt++ > g.size()) break;
    }

    int cycleVertex = -1;
    for (int v = 0; v < g.size(); v++){
        for (auto &[to, weight] : g[v]){
            if (dist[to] != INF && dist[to] > dist[v] + weight) {
                cycleVertex = to;
            }
        }
    }
    
    if (cycleVertex != -1) {
        cout << "YES\n";
        printPath(from, q.front());
    } else cout << "NO";
}

int main(){
    int n;
    cin >> n;

    vector<vector<ii>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int weight;
            cin >> weight;
            if (weight != 10E5) {
                g[i].push_back({ j, weight });
            }
        }
    }

    fordBellman(g, 0);

    return 0;
}