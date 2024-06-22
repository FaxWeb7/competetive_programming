#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, d; cin >> n >> d;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // можно ли добраться до лианы с номером i
    vector<bool> dp(n + 1);
    dp[1] = true;
    for (int i = 1; i <= n; ++i){
        if (dp[i]){
            int cnt = (a[i-1]/d);
            for (int j = 1; j <= cnt; ++j) dp[i+j] = true;
        }
    }


    for(int i = n; i >= 0; --i){
        if (dp[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}
