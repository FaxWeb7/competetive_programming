#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> ii;

const int INF = 1E9;
const vi dy = {1, -1, 0, 0};
const vi dx = {0, 0, 1, -1};

string getPath(vector<vector<ii>> &from, int finishY, int finishX){
    string path;

    ii curCoord = { finishY, finishX };
    ii fromCoord = from[curCoord.first][curCoord.second];
    while (fromCoord != ii{ -1, -1 }){
        int yDiff = curCoord.first - fromCoord.first;
        int xDiff = curCoord.second - fromCoord.second;

        if (yDiff == 1) path.push_back('S');
        else if (yDiff == -1) path.push_back('N');
        else if (xDiff == 1) path.push_back('E');
        else if (xDiff == -1) path.push_back('W');

        curCoord = fromCoord;
        fromCoord = from[curCoord.first][curCoord.second];
    }
    reverse(path.begin(), path.end());

    return path;
}

pair<int, vector<vector<ii>>> bfs(vs &g, int startY, int startX, int finishY, int finishX){
    int h = g.size(), w = g[0].size();
    vector<vi> dist(h, vi(w, INF));
    vector<vector<ii>> from(h, vector<ii>(w, { -1, -1 }));
    deque<ii> q;

    dist[startY][startX] = 0;
    q.push_back({ startY, startX });

    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop_front();

        if (y == finishY && x == finishX){
            return {dist[y][x], from};
        }

        for (size_t d = 0; d < dy.size(); d++){
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (ty >= 0 && tx >= 0 && ty < h && tx < w && g[ty][tx] != '#'){
                if (g[ty][tx] == 'W' && dist[ty][tx] > dist[y][x] + 2){
                    dist[ty][tx] = dist[y][x] + 2;
                    from[ty][tx] = { y, x };
                    q.push_back({ ty, tx });
                } else if (g[ty][tx] == '.' && dist[ty][tx] > dist[y][x] + 1){
                    dist[ty][tx] = dist[y][x] + 1;
                    from[ty][tx] = { y, x };
                    q.push_front({ ty, tx });
                }
            }
        }
    }

    return {-1, from};
}

int main(){
    int n, m, startY, startX, finishY, finishX;
    cin >> n >> m >> startY >> startX >> finishY >> finishX;
    startY--; startX--; finishY--; finishX--;

    vs g(n);
    for (int y = 0; y < n; y++){
        cin >> g[y];
    }

    auto bfsRes = bfs(g, startY, startX, finishY, finishX);
    cout << bfsRes.first << endl;
    if (bfsRes.first != -1){
        cout << getPath(bfsRes.second, finishY, finishX);
    }

    return 0;
}