#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<string, int> si;


class Solution {
public:
    void dfs(vector<vector<int>> &visited, int n, int m, int i, int j){
        visited[i][j] = 1;
        if (i+1 < n) dfs(visited, n, m, i+1, j);
        if (i-1 >= 0) dfs(visited, n, m, i-1, j);
        if (j+1 < m) dfs(visited, n, m, i, j+1);
        if (j-1 >= 0) dfs(visited, n, m, i, j-1);
    }

    int numIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();

        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (g[i][j] == '1' && !visited[i][j]){
                    dfs(visited, n, m, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution sol = Solution();

    return 0;
}