#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = 1;
    }

    string ans = "YES";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && (!graph[i][j] && !graph[j][i])) {
                ans = "NO";
                break;
            }
        }
    }
    cout << ans;

    return 0;
}