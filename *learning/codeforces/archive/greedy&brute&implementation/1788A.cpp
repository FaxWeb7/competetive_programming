#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vi a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) cnt1++;
        else cnt2++;
    }

    if (cnt2 % 2 != 0) cout << -1 << '\n';
    else {
        int cur2 = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] == 2) cur2++;
            if (cur2 == cnt2/2) {
                cout << i+1 << '\n';
                return;
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}