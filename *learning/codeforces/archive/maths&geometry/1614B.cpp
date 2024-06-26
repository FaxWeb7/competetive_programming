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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    priority_queue<pii> pq;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pq.push({ x, i });
    }

    int res = 0;
    bool q = true;
    int cnt = 2;
    while (!pq.empty()){
        pii p = pq.top();
        pq.pop();

        int val = (q ? cnt/2 : -cnt/2);
        res += 2*abs(val)*p.F;
        a[p.S] = val;
        cnt++, q = !q;
    }

    cout << res << "\n0 ";
    for (int &x : a) cout << x << ' ';
    cout << '\n';
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
