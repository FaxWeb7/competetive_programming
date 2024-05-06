#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

const int INF = 1E9;

vector<int> getPath(vector<int>& from, int finish){
    // функция для восстановления кратчайшего пути из 0 в finish
    vector<int> path;
    for (int v = finish; v != -1; v = from[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

pair<vector<int>, vector<int>> bfs(vector<vector<int>>& graph, int start){
    vector<int> dist(graph.size(), INF);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (int to : graph[v]){
            if (dist[to] > dist[v] + 1){ //if dist[to] == INF
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    return { dist, from };
}

void bfs(vector<string> &graph, int startY, int startX, int finishY, int finishX){
    // bfs на 0-1 графе (задача найти кротчайший путь в матрице и потратить минимальное количество здоровья, где S - старт, F - финиш, # - стена, точка - тропинки, за проход по которому тратится 0 здоровья, G - стражник, который отнимает 1 здоровье)
    // очередь заменяется на дек, и события типа 0 помещаются в начало дека, а 1 помещаетсяв конеч дека, так как нам приоритетнее наткнуться на наименьшее кол-во стражников
    
    int h = graph.size(), w = graph[0].size();
    vector<vector<int>> dist(h, vector<int>(w, INF));
    vector<vector<pair<int,int>>> from(h, vector<pair<int,int>>(w, {-1, -1}));
    deque<pair<int, int>> deq;

    dist[startY][startX] = 0;
    deq.push_back({ startY, startX });

    vector<int> dy = {1, -1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};

    while (!deq.empty()){
        auto [y, x] = deq.front();
        deq.pop_front();

        for (int d = 0; d < dy.size(); d++){
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (ty >= 0 && tx >= 0 && ty < h && tx < w){
                if (graph[ty][tx] == 'G' && dist[ty][tx] > dist[y][x] + 1){
                    dist[ty][tx] = dist[y][x] + 1;
                    from[ty][tx] = { y, x };
                    deq.push_back({ ty, tx });
                } else if (graph[ty][tx] == '.' && dist[ty][tx] > dist[y][x]){
                    dist[ty][tx] = dist[y][x];
                    from[ty][tx] = { y, x };
                    deq.push_front({ ty, tx });
                }
            }
        }
    }
}