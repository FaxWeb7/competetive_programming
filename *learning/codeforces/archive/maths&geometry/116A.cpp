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

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int ai, bi; cin >> ai >> bi;
        cnt = cnt - ai + bi;
        ans = max(ans, cnt);
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}