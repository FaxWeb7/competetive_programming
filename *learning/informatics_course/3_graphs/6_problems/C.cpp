#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    vector<vi> dist(n, vi(n, INF));
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            int weight;
            cin >> weight;
            dist[a][b] = min(dist[a][b], weight);
        }
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

    for (int a = 0; a < n; a++){
        if (dist[a][a] < 0) {
            cout << -1;
            return 0;
        }
    }


    int minPath = INF;
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            if (a != b){
                minPath = min(minPath, dist[a][b]);
            }
        }
    }
    cout << minPath;

    return 0;
}
