#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1E9;

vi getPath(vector<vi> &from, int start, int finish){
    vi path;
    for (int v = finish; v != -1; v = from[start][v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> dist(n, vi(n, INF));
    vector<vi> from (n, vi(n, -1));
    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        a--, b--;
        if (dist[a][b] > weight){
            dist[a][b] = weight;
            from[a][b] = a;
        }
    }

    for (int v = 0; v < n; v++){
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                if (dist[a][v] != INF && dist[v][b] != INF && dist[a][b] > dist[a][v] + dist[v][b]){
                    dist[a][b] = dist[a][v] + dist[v][b];
                    from[a][b] = from[v][b];
                }
            }
        }
    }

    return 0;
}