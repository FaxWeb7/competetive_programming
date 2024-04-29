#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 1e9;

int getStart(vector<vi> &dist, vector<vector<ii>> &from, vector<ii> &starts, int finishY, int finishX){
    ii ansStart;
    for (ii v = { finishY, finishX }; v != ii{-1, -1}; v = from[v.first][v.second]){
        ansStart = v;
    }
    
    for (int i = 0; i < starts.size(); ++i){
        if (starts[i] == ansStart) {
            return i+1;
        }
    }

    return -1;
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
        cout << getStart(dist, from, starts, finishY, finishX);
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// typedef vector<int> vi;
// typedef pair<int, int> ii;
// const int INF = 1e9;

// int main(){
//     int n, m, finishY, finishX;
//     cin >> n >> m;

//     vector<vector<vector<vi>>> dist(n, vector<vector<vi>>(m, vector<vi>(n, vi(m, INF))));
//     for (int a = 0; a < n; ++a){
//         for (int b = 0; b < n; ++b){
//             char s;
//             cin >> s;
//             if (s == '*') {
//                 finishY = a;
//                 finishX = b;
//             } else if (s == '0'){
//                 dist[a][b][a][b] = min(1, dist[a][b][a][b]);
//             }
//         }
//     }

//     int k;
//     cin >> k;
//     vector<ii> starts(k);
//     for (auto &[y, x] : starts){
//         cin >> y >> x;
//         y--, x--;
//     }

//     for (int v = 0; v < n; v++){
//         for (int a = 0; a < n; a++){
//             for (int b = 0; b < n; b++){
//                 if (dist[a][v] != INF && dist[v][b] != INF && dist[a][b] > dist[a][v] + dist[v][b]){
//                     dist[a][b] = dist[a][v] + dist[v][b];
//                 }
//             }
//         }
//     }

//     for (auto &[y, x] : starts){
//         cout << dist[y][x][finishY][finishX] << '\n';
//     }

//     return 0;
// }