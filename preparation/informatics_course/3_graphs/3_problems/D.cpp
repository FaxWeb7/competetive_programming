#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int ,int> ii;

const int INF = 1E9;

int bfs(vector<vi> &g, vector<ii> &starts){
    vector<vi> dist(8, vi(8, INF));
    queue<ii> q;

    for (auto &start : starts){
        dist[start.first][start.second] = 0;
        q.push({ start.first, start.second });
    }

    vi dy = {2, 2, -2, -2, 1, -1, 1, -1};
    vi dx = {1, -1, 1, -1, 2, 2, -2, -2};

    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++){
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (ty >= 0 && tx >= 0 && ty < 8 && tx < 8){
                if (g[ty][tx] == 1) {
                    return dist[y][x]+1;
                }
                if (dist[ty][tx] > dist[y][x] + 1){
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                    g[ty][tx] = 1;
                    g[y][x] = 0;
                }
            }
        }
    }
    return -1;
}

int main(){
    //PROBLEMS: лишние вершины одновременно + старт только с одной вершины
    vector<vi> g(8, vi(8, 0));
    vector<ii> starts;
    for (int i = 0; i < 2; i++){
        string pos;
        cin >> pos;
        starts.push_back({pos[1] - '1', pos[0] - 'a'});
        g[pos[1] - '1'][pos[0] - 'a'] = 1;
    }

    cout << bfs(g, starts) << endl;

    return 0;
}