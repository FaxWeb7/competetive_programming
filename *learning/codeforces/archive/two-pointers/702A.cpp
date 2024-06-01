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
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 1;
    int r = 0;
    for (int l = 0; l < n; ++l){
        while (r < n-1 && a[r+1] > a[r]) {
            r++;
        }

        ans = max(ans, r-l+1);
        l = r;
        r++;
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}