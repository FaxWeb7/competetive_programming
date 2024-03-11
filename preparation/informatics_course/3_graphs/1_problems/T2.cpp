#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string ans = "YES";
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (graph[a][b] || graph[b][a]) ans = "NO";
        graph[a][b] = 1;
    }
    
    cout << ans;

    return 0;
}