#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int maxT, startT, n; cin >> maxT >> startT >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = startT - 1 + 1;
    for (int &ai : a){
        if (ai < maxT) ans += ai;
        else ans += maxT-1;
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