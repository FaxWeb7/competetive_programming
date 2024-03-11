#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string ans = "NO";
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (graph[a][b] || graph[b][a]){
            ans = "YES";
        }
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout << ans;

    return 0;
}