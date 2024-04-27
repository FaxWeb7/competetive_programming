#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    string ans = "YES";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (graph[i][j]){
                for (int k = 0; k < n; k++){
                    if (graph[j][k] && !graph[i][k] && i != k) ans = "NO";
                }
            }
        }
    }

    cout << ans;

    return 0;
}