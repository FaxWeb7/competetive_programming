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
    vector<int> colors(n);
    for (int i = 0; i < n; i++) cin >> colors[i];

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (graph[i][j] && colors[i] != colors[j]){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}