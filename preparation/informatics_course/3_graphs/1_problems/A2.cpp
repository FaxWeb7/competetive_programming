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
        for (int j = i+1; j < n; j++){
            if (graph[i][j] != graph[j][i]){
                ans = "NO";
                break;
            }
        }
        if (graph[i][i] == 1){
            ans = "NO";
            break;
        }
    }

    cout << ans;

    return 0;
}