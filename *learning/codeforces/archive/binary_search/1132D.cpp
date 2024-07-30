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
#define type pair<int, pii>
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int i = 0; i < n; ++i) c[i] = a[i] / b[i];

    int l = 0, r = 2000000005;
    while (l < r){
        int mid = l + (r - l) / 2;

        int f = 1;
        priority_queue<type, vector<type>, greater<type>> pq;
        for (int i = 0; i < n; ++i) pq.push({c[i], {i, a[i]}});
        for (int i = 0; i < k-1; ++i){
            type p = pq.top();
            pq.pop();

            int x = p.S.S + mid;
            pq.push({x / b[p.S.F], {p.S.F, x}});

            if (pq.top().F <= i) {
                f = 0;
                break;
            }
        }
        if (f) r = mid;
        else l = mid + 1;
    }

    cout << (l == 2000000005 ? -1 : l);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}