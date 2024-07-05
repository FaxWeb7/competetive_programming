#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int sum = 0;
    int mx = b[0];
    int maxScore = 0;
    for (int i = 0; i < n; ++i){
        sum += a[i];
        mx = max(mx, b[i]);

        if (i+1 <= k){
            int curScore = sum + (k - (i+1)) * mx;
            maxScore = max(maxScore, curScore);
        }
    }

    cout << maxScore << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}