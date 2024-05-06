#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    int n, start, finish;
    cin >> n >> start >> finish;
    start--, finish--;

    vector<vi> dist(n, vi(n, INF));
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            int weight;
            cin >> weight;
            if (weight != -1 && dist[a][b] > weight){
                dist[a][b] = weight;
            }
        }
        dist[a][a] = 0;
    }

    for (int v = 0; v < n; v++){
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                if (dist[a][v] != INF && dist[v][b] != INF && dist[a][b] > dist[a][v] + dist[v][b]){
                    dist[a][b] = dist[a][v] + dist[v][b];
                }
            }
        }
    }

    cout << (dist[start][finish] != INF ? dist[start][finish] : -1);

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;
// typedef vector<int> vi;
// typedef pair<int, int> ii;
// const int INF = 1e9;

// int dijkstra(vector<vector<ii>> &g, int start, int finish){
//     vi dist(g.size(), INF);
//     set<ii> q;

//     dist[start] = 0;
//     q.insert({ dist[start], start });
//     while (!q.empty()){
//         int nearest = q.begin()->second;
//         q.erase(q.begin());

//         for (auto &[to, weight] : g[nearest]){
//             if (dist[to] > dist[nearest] + weight){
//                 q.erase({ dist[to], to });
//                 dist[to] = dist[nearest] + weight;
//                 q.insert({ dist[to], to });
//             }
//         }
//     }

//     return dist[finish] != INF ? dist[finish] : -1;
// }

// int main(){
//     int n, start, finish;
//     cin >> n >> start >> finish;
//     start--, finish--;

//     vector<vector<ii>> g(n);
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             int weight;
//             cin >> weight;
//             if (weight != -1) g[i].push_back({ j, weight });
//         }
//     }

//     cout << dijkstra(g, start, finish);

//     return 0;
// }