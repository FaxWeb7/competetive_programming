#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int INF = 1E9;

int main(){
    int n;
    cin >> n;

    vector<vi> dist(n, vi(n, 0));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> dist[i][j];
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

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

