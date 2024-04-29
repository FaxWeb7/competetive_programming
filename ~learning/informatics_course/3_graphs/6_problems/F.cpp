#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 1e9;

void printPath(vector<vi> &dist, vector<vector<ii>> &from, int finishY, int finishX){
    vector<ii> path;
    for (ii v = { finishY, finishX }; v != ii{-1, -1}; v = from[v.first][v.second]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (auto &[y, x] : path){
        cout << y+1 << ' ' << x+1 << '\n';
    }
}

pair<vector<vi>, vector<vector<ii>>> bfs(vector<string> &g, vector<ii> &starts){
    int h = g.size(), w = g[0].size();
    vector<vi> dist(h, vi(w, INF));
    vector<vector<ii>> from(h, vector<ii>(w, {-1, -1}));
    queue<ii> q;

    for (auto &[y, x] : starts){
        dist[y][x] = 0;
        q.push({ y, x });
    }

    vi dy = {1, -1, 0, 0};
    vi dx = {0, 0, -1, 1};
    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        if (g[y][x] == '*'){
            return {dist, from};
        }

        for (int d = 0; d < dy.size(); ++d){
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (ty >= 0 && tx >= 0 && ty < h && tx < w && g[ty][tx] != '1' && dist[ty][tx] > dist[y][x] + 1){
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = { y, x };
                q.push({ ty, tx });
            }
        }
    }

    return {dist, from};
}

int main(){
    int n, m, finishY, finishX;
    cin >> n >> m;

    vector<string> g(n);
    for (int a = 0; a < n; ++a){
        cin >> g[a];
        for (int b = 0; b < n; ++b){
            if (g[a][b] == '*') {
                finishY = a;
                finishX = b;
            }
        }
    }

    int k;
    cin >> k;
    vector<ii> starts(k);
    for (auto &[y, x] : starts){
        cin >> y >> x;
        y--, x--;
    }

    auto [dist, from] = bfs(g, starts);
    if (dist[finishY][finishX] == INF) {
        cout << -1;
    } else {
        cout << dist[finishY][finishX] << '\n';
        printPath(dist, from, finishY, finishX);
    }

    return 0;
}