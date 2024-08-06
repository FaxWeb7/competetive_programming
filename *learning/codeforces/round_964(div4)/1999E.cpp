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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const int N = 2e5+20;

vi pref(N);

void solve(){
    int l, r; cin >> l >> r;
    cout << (pref[l]-pref[l-1]) + (pref[r]-pref[l-1]) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 0; i < N; ++i){
        int num = i;
        int c = 0;
        while (num > 0) {
            num /= 3;
            ++c;
        }
        pref[i] = pref[i-1] + c;
    }

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}