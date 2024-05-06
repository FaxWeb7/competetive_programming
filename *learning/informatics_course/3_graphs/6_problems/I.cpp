#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> dist(n, vi(n, INF));
    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i){
        int a, b, weight;
        cin >> a >> b >> weight;
        a--, b--;
        dist[a][b] = min(dist[a][b], weight);
        dist[b][a] = min(dist[b][a], weight);
    }

    for (int v = 0; v < n; v++){
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                if (dist[a][v] != INF && dist[v][b] != INF && dist[a][b] > dist[a][v] + dist[v][b]){
                    dist[a][b] = dist[a][v] + dist[v][b];
                }
            }
        }
    }

    pair<int, int> res; // {maxDiff, index}
    for (int a = 0; a < n; a++){
        int maxDiff = -1E9;
        for (int b = 0; b < n; b++){
            maxDiff = max(maxDiff, dist[a][b]);
        }
        if (res == pair<int, int>{} || maxDiff < res.first) {
            res = { maxDiff, a+1 };
        }
    }

    cout << res.second;

    return 0;
}