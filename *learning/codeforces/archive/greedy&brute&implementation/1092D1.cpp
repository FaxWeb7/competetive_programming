#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 2;
    }

    vi st;
    for (int i = 0; i < n; ++i){
        if (!st.empty() && a[i] == st.back()) st.pop_back();
        else st.pb(a[i]);
    }

    cout << (st.size() <= 1 ? "YES\n" : "NO\n");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}