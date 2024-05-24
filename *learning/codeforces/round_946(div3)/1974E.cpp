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
#define int ll
const int INF = 1e18 + 20;
const int N = 1e5 + 20;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int m, x; cin >> m >> x;

        // dp[i] => макс. число денег которое можно иметь при счастье равному i
        vector<int> dp{0};

        int c[N], h[N];
        for (int i = 0; i < m; ++i){
            cin >> c[i] >> h[i];
            for (int j = 0; j < h[i]; ++j){
                dp.push_back(-INF);
            }
        }

        for (int i = 0; i < m; ++i){
            for (int j = dp.size()-1; j >= 0; --j){
                dp[j] += x;
                if (j >= h[i] && dp[j - h[i]] >= c[i]){
                    dp[j] = max(dp[j], dp[j - h[i]] - c[i] + x);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < dp.size(); ++i){
            if (dp[i] >= 0) ans = i;
        }
        cout << ans << '\n';
    }

    return 0;
}