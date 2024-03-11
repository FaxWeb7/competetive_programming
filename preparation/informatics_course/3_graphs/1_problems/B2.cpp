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

    string ans = "NO";
    for (int i = 0; i < n; i++){
        if (graph[i][i] == 1){
            ans = "YES";
            break;
        }
    }

    cout << ans;

    return 0;
}