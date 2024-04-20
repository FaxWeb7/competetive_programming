#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 1E9;

int countPathLen(vector<vi> &g, int startY, int startX, vector<ii>& finishCoords){
    int h = g.size(), w = g[0].size();

    vector<vi> dist(h, vi(w, INF));
    queue<ii> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vi dy = {-1, 1, 0, 0};
    vi dx = {0, 0, 1, -1};

    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++){
            int ty = y + dy[d];
            int tx = x + dx[d];

            for (ii coords : finishCoords){
                if (coords == ii{ ty, tx }){
                    return dist[y][x] + 1;
                }
            }

            if (ty >= 0 && tx >= 0 && ty < h && tx < w && g[ty][tx] != 1 && dist[ty][tx] > dist[y][x] + 1){
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vi> g(n, vi(m));
    vector<ii> finishCoords;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            cin >> g[y][x];
            if (g[y][x] == 1) {
                finishCoords.push_back({ y, x });
            }
        }
    }

    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            if (g[y][x] != 1) {
                cout << countPathLen(g, y, x, finishCoords) << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}