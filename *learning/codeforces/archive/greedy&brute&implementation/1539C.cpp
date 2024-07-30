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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, k, x; cin >> n >> k >> x;
    vi a(n);
    for (int &v : a) cin >> v;
    sort(all(a));

    int ans = 1;
    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < n-1; ++i){
        if (a[i+1] - a[i] > x) {
            ans++;
            pq.push((a[i+1]-a[i]) - x);
        }
    }

    while (!pq.empty()){
        int v = pq.top();
        pq.pop();

        int need = (v + x - 1) / x;
        if (need > k) break;

        k -= need;
        ans--;
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}
