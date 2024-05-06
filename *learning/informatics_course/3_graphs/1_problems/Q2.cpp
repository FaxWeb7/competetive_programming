#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    string ans = "YES";
    for (int i = 0; i < n-1; i++){
        if (graph[i].size() != graph[i+1].size()) {
            ans = "NO"; 
            break;
        }
    }

    cout << ans;

    return 0;
}