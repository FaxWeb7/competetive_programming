#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1E9;

struct Vertex {
    int y;
    int x;
    int dir; // 0-up, 1-right, 2-down, 3-left
    Vertex(int y, int x, int dir) : y(y), x(x), dir(dir) {}
};

vector<Vertex> getOptions(vs &g, Vertex v){
    int h = g.size(), w = g[0].size();
    vector<Vertex> options;
    vi dy = {-1, 0, 1, 0};
    vi dx = {0, 1, 0, -1};
    
    int ty = v.y + dy[v.dir];
    int tx = v.x + dx[v.dir];
    if (ty >= 0 && tx >= 0 && ty < h && tx < w && g[ty][tx] != 'X'){
        options.push_back({ ty, tx, v.dir });
    }

    ty = v.y + dy[(v.dir + 1) % 4];
    tx = v.x + dx[(v.dir + 1) % 4];
    if (ty >= 0 && tx >= 0 && ty < h && tx < w && g[ty][tx] != 'X'){
        options.push_back({ ty, tx, (v.dir + 1) % 4 });
    }

    return options;
}

int bfs(vs &g, pair<int, int> start){
    int h = g.size(), w = g[0].size();
    vector<vector<vi>> dist(h, vector<vi>(w, vi(4, INF)));
    queue<Vertex> q;

    dist[start.first][start.second][0] = 0;
    dist[start.first][start.second][1] = 0;
    dist[start.first][start.second][2] = 0;
    dist[start.first][start.second][3] = 0;
    q.push({ start.first, start.second, 0 });
    q.push({ start.first, start.second, 1 });
    q.push({ start.first, start.second, 2 });
    q.push({ start.first, start.second, 3 });

    while (!q.empty()){
        Vertex v = q.front();
        q.pop();

        if (g[v.y][v.x] == 'F'){
            return dist[v.y][v.x][v.dir];
        }

        for (Vertex &option : getOptions(g, v)){
            if (dist[option.y][option.x][option.dir] > dist[v.y][v.x][v.dir] + 1){
                dist[option.y][option.x][option.dir] = dist[v.y][v.x][v.dir] + 1;
                q.push(option);
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vs g(n);
    pair<int, int> start;
    for (int y = 0; y < n; y++){
        getline(cin, g[y]);
        for (int x = 0; x < m; x++){
            if (g[y][x] == 'S') start = { y, x };
        }
    }

    cout << bfs(g, start);

    return 0;
}