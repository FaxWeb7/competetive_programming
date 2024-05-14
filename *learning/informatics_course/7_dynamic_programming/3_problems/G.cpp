// #include <iostream>
// #include <vector>
// using namespace std;
// const int INF = 1e9;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> w(n + 1);
//     for (int i = 1; i <= n; ++i) cin >> w[i];

//     // dp[i] => можно ли разложить первые i гирь равномерно
//     vector<bool> dp(n + 1);
//     dp[0] = true;
//     dp[1] = false;
//     for (int i = 2; i <= n; ++i){
//         if (dp[i-1]){
//             dp[i] = false;
//         } else {

//         }
//     }


//     cout << (dp[n].second ? "YES" : "NO");

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

bool canBalanceWeights(vector<int>& weights, int totalWeight, int currentIndex) {
    if (totalWeight == 0) {
        return true;
    }
    if (currentIndex >= weights.size() || totalWeight < 0) {
        return false;
    }
    
    return canBalanceWeights(weights, totalWeight, currentIndex+1) || canBalanceWeights(weights, totalWeight - weights[currentIndex], currentIndex+1);
}

int main() {
    int N;
    cin >> N;
    
    vector<int> weights(N);
    int totalWeight = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
        totalWeight += weights[i];
    }
    
    if (totalWeight % 2 != 0) {
        cout << "NO" << endl;
    } else {
        if (canBalanceWeights(weights, totalWeight/2, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}