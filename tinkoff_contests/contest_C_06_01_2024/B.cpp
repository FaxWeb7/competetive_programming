#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<char>>& matrix, int n, int m, int guess) {
    for (int l = 0; l <= n - (3 * guess); l++) {
        for (int k = guess; k < m - guess - (guess - 1); k++) {
            bool isFit = true;
            for (int i = l; i < l + guess; i++) {
                for (int j = k; j < k + guess; j++) {
                    if (matrix[i][j] != '#') {
                        isFit = false;
                        break;
                    }
                }
                if (!isFit) break;
            }
            if (!isFit) continue;
            for (int i = l + guess; i < l + (2 * guess); i++) {
                for (int j = k - guess; j < k + (2 * guess); j++) {
                    if (matrix[i][j] != '#') {
                        isFit = false;
                        break;
                    }
                }
                if (!isFit) break;
            }
            if (!isFit) continue;
            for (int i = l + (2 * guess); i < l + (3 * guess); i++) {
                for (int j = k; j < k + guess; j++) {
                    if (matrix[i][j] != '#') {
                        isFit = false;
                        break;
                    }
                }
                if (!isFit) break;
            }
            if (isFit) return true;
        }
    }

    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf(" %c", &matrix[i][j]);
    }

    int left = 1;
    int right = max(n, m);
    while (left < right){
        int mid = (left+right+1) / 2;
        if (check(matrix, n, m, mid)){
            left = mid;
        } 
        else {
            right = mid-1;
        }
    }

    printf("%d", left);
    return 0;
}