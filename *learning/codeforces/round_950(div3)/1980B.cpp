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

bool comp(int a, int b){
    return a > b;
}

void solve(){
    int n, f, k; cin >> n >> f >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int best = a[f-1];
    sort(all(a), comp);

    int ans = 2;
    for (int i = 0; i < k; ++i){
        if (a[i] == best) {
            ans = 1;
        }
    }

    if (ans == 1 && k < n && a[k] == best) ans = 3;
    cout << (ans == 1 ? "YES" : ans == 2 ? "NO" : "MAYBE") << '\n';
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