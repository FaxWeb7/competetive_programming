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

    int minPathSum = 5000;
    vector<int> ans(3);
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                int curPathSum = graph[i][j] + graph[k][i] + graph[j][k];
                minPathSum = min(minPathSum, curPathSum);
                if (minPathSum == curPathSum){
                    ans = {i+1, j+1, k+1};
                }
            }
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];
    
    return 0;
}