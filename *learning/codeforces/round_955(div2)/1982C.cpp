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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, minSum, maxSum; cin >> n >> minSum >> maxSum;
    vi a(n);
    for (int &x : a) cin >> x;

    int res = 0, curSum = a[0];
    for (int l = 0, r = 0; l < n; ++l){
        while (r+1 < n && curSum < minSum) curSum += a[++r];

        if (curSum >= minSum && curSum <= maxSum){
            res++;
            l = r;
            r++;
            curSum = a[r];
        } else {
            curSum -= a[l];
        }
    }

    cout << res << '\n';
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