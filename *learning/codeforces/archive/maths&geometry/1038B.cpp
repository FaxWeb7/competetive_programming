#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

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
    int n; cin >> n;

    vi pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + i;
    
    for (int k = 1; k < n; ++k){
        if (gcd(pref[k], pref[n] - pref[k]) > 1){
            cout << "Yes\n" << k << ' ';
            for (int i = 1; i <= k; ++i) cout << i << ' ';
            cout << '\n' << n-k << ' ';
            for (int i = k+1; i <= n; ++i) cout << i << ' ';
            cout << '\n';

            return;
        }
    }

    cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}