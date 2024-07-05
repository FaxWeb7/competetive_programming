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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

int ceil_div(int a, int b){
    return (a + (b - 1)) / b;
}

void solve(){
    int n, m, k, c; cin >> n >> m >> k >> c;
    
    int res = 0;

    int full = 0;
    int pos = c;
    for (int i = 0; i < k; ++i){
        full += ceil_div(m - (--pos), k);
        if (pos == 0) pos = k;
    }

    res += full * (n / k);
    pos = c;
    for (int i = 0; i < n % k; ++i){
        res += ceil_div(m - (--pos), k);
        if (pos == 0) pos = k;
    }

    cout << res;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}