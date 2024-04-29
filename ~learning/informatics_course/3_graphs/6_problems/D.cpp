#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    vector<vi> dist(n, vi(n, INF));
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            cin >> dist[a][b];
        }
    }

    for (int v = 0; v < n; v++){
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                if (dist[a][v] && dist[v][b]){
                    dist[a][b] = 1;
                }
            }
        }
    }

    for (int a = 0; a < n; a++){
        if (dist[a][a] != 0) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;
// typedef vector<int> vi;
// const int INF = 1e9;

// void dfs(vector<vi> &g, int v, vi &visited, bool &hasCycle){
//     visited[v] = 1;
//     for (int &to : g[v]){
//         if (visited[to] == 0){
//             dfs(g, to, visited, hasCycle);
//         } else if (visited[to] == 1){
//             hasCycle = true;
//             return;
//         }
//     }
//     visited[v] = 2;
// }

// int main(){
//     int n;
//     cin >> n;

//     vector<vi> g(n);
//     for (int a = 0; a < n; a++){
//         for (int b = 0; b < n; b++){
//             int weight;
//             cin >> weight;
//             if (weight != 0) g[a].push_back(b);
//         }
//     }

//     vi visited(n);
//     bool hasCycle = false;
//     for (int v = 0; v < n; v++){
//         if (!visited[v]){
//             dfs(g, v, visited, hasCycle);
//         }
//     }

//     cout << (hasCycle ? 1 : 0);

//     return 0;
// }