// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> ii;
// #define all(x) x.begin(), x.end()
// #define MP make_pair
// #define F first
// #define S second
// const int INF = 1e9;


// int main(){
//     int t;
//     cin >> t;
//     while (t--){
//         int p1, p2, p3;
//         cin >> p1 >> p2 >> p3;

//         // dp[i][j][k] => макс. кол-во ничей к моменту игры когда размеры куч равны i, j и к соответственно
//         vector<vector<vi>> dp(p1 + 1, vector<vi>(p2 + 1, vi(p3 + 1, -1)));
//         dp[0][0][0] = 0;
//         for (int i = 0; i <= p1; ++i){
//             for (int j = 0; j <= p2; ++j){
//                 for (int k = 0; k <= p3; ++k){
//                     if (i-2 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-2][j][k]);
//                     if (j-2 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-2][k]);
//                     if (k-2 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-2]);
//                     if (i-1 >= 0 && j-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]);
//                     if (i-1 >= 0 && k-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
//                     if (j-1 >= 0 && k-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);

//                     if ((i-1 >= 0 && j-1 >= 0 && dp[i][j][k] == dp[i-1][j-1][k] && dp[i-1][j-1][k] != -1) || (i-1 >= 0 && k-1 >= 0 && dp[i][j][k] == dp[i-1][j][k-1] && dp[i-1][j][k-1] != -1) || (j-1 >= 0 && k-1 >= 0 && dp[i][j][k] == dp[i][j-1][k-1] && dp[i][j-1][k-1] != -1)) dp[i][j][k]++;
//                 }
//             }
//         }

//         cout << dp[p1][p2][p3] << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;


int main(){
    int t;
    cin >> t;
    while (t--){
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        if ((p1 + p2 + p3) % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }

        if (p1 + p2 >= p3) cout << (p1 + p2 + p3) / 2 << '\n';
        else cout << p1 + p2 << '\n';
    }

    return 0;
}