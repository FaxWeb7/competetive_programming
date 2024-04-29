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

    int ans = 0;
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            if (dist[a][b] != INF){
                ans = max(ans, dist[a][b]);
            }
        }
    }

    cout << ans;

    return 0;
}