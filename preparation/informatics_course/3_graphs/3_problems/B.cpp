#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1E9;
vector<int> dx = {1, 1, 2, 2, -1, -1, -2, -2};
vector<int> dy = {2, -2, 1, -1, 2, -2, 1, -1};


bool isValid(int y, int x, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

vector<ii> getShortPath(vector<vi>& graph, int x1, int y1, int x2, int y2, int n){
    vector<vi> dist(n, vi(n, INF));
    vector<vector<ii>> from(n, vector<ii>(n, {-1, -1}));
    queue<ii> q;

    dist[y1][x1] = 0;
    q.push({ y1, x1 });

    while (!q.empty()){
        ii v = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            ii to = {v.first + dy[i], v.second + dx[i]};

            if (isValid(to.first, to.second, n) && dist[to.first][to.second] > dist[v.first][v.second] + 1) {
                dist[to.first][to.second] = dist[v.first][v.second] + 1;
                from[to.first][to.second] = { v.first, v.second };
                q.push(to);
            }
        }
    }

    vector<ii> path;
    for (ii v = { y2, x2 }; v != ii{ y1, x1 }; v = from[v.first][v.second]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    vector<vi> graph(n, vi(n));

    vector<ii> path = getShortPath(graph, x1, y1, x2, y2, n);
    cout << path.size() << endl;
    for (ii i : path){
        cout << i.second+1 << " " << i.first+1 << endl;
    }

    return 0;
}
