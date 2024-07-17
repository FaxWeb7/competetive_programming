#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>

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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    bool has1 = false, has2 = false;
    for (int &x : a) {
        cin >> x;
        if (x % 2) has1 = true;
        else has2 = true;
    }
    if (has1 && has2){
        cout << 2 << '\n';
        return;
    }

    int ans = 4;
    for (int i = 1; i < 60; ++i){
        set<int> st;
        for (int i = 0; i < n; ++i){
            if (st.size() > 2) break;
            st.insert(a[i]%ans);
        }
        if (st.size() == 2) break;
        ans *= 2;
    }

    cout << ans << '\n';
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