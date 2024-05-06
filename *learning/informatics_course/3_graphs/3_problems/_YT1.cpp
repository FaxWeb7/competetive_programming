#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
example input:
8 10
...#......
......#.F.
...#######
..........
#######.##
.....#....
.S.#.#....
...#......
*/

const int INF = 1E9;

void writePath(vector<vector<pair<int, int>>> from, vector<string>& g, int finishY, int finishX){
    vector<pair<int, int>> path;
    for (pair<int, int> v = {finishY, finishX}; v != pair<int, int>{-1, -1}; v = from[v.first][v.second]){
        path.push_back(v);
        g[v.first][v.second] = '*';
    }
}

pair<vector<vector<pair<int, int>>>, int> bfs(vector<string>& g, int startY, int startX, int finishY, int finishX){
    int h = g.size(), w = g[0].size();

    vector<vector<int>> dist(h, vector<int>(w, INF));
    vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, {-1, -1}));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({startY, startX}); 

    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, 1, -1};

    while (!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            
            if (0 <= ty && 0 <= tx && ty < h && tx < w && 
                g[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1){
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = {y, x};
                q.push({ ty, tx });
            }
        }
    }

    return {from, dist[finishY][finishX]};
}

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> g(h);
    int startX, startY, finishX, finishY;

    for (int y = 0; y < h; y++){
        cin >> g[y];
        for (int x = 0; x < w; x++){
            if (g[y][x] == 'S'){
                startY = y;
                startX = x;
            } else if (g[y][x] == 'F'){
                finishY = y;
                finishX = x;
            }
        }
    }

    auto bfsResult = bfs(g, startY, startX, finishY, finishX);
    int stepCount = bfsResult.second;
    auto from = bfsResult.first;
    if (stepCount != INF){
        cout << endl << stepCount << endl;
        writePath(from, g, finishY, finishX);
        for (auto& row : g){
            cout << row << endl;
        }
    } else cout << "Impossible";

    return 0;
}