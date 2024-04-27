#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;

int bfs(vector<vi> &g, int h, int w){
    vector<vi> dist(h, vi(w, INF));
    queue<ii> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });

    vi dy = {1, -1, 0, 0};
    vi dx = {0, 0, 1, -1};
    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop();
        for (int d = 0; d < dy.size(); d++){
            int ty = y;
            int tx = x;
            while (ty + dy[d] >= 0 && tx + dx[d] >= 0 && ty + dy[d] < h && tx + dx[d] < w && g[ty + dy[d]][tx + dx[d]] != 1){
                if (g[ty][tx] == 2){
                    return dist[y][x] + 1;
                }
                ty += dy[d];
                tx += dx[d];
            }
            if (g[ty][tx] == 2){
                return dist[y][x] + 1;
            }
            if (dist[ty][tx] > dist[y][x] + 1){
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ty, tx});
            }
        }
    }

    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> g(n, vi(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    cout << bfs(g, n, m);

    return 0;
}