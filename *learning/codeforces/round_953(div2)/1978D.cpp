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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, c; cin >> n >> c;
    vi a(n);
    int maxIdx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) a[i] += c;
        if (a[i] > a[maxIdx]) maxIdx = i;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i){
        if (i == maxIdx) cout << 0 << ' ';
        else if (sum+a[i] >= a[maxIdx]) cout << i << ' ';
        else cout << i+1 << ' ';
        sum += a[i];
    }
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