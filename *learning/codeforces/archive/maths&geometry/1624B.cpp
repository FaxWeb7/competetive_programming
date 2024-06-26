#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    int xa = ((b - (c-b)) / a);
    int newA = a * xa;
    int xb = (((a + c) / 2) / b);
    int newB = b * xb;
    int xc = ((b + (b - a)) / c);
    int newC = c * xc;

    if ((xa > 0 && c - b == b - newA) || (xb > 0 && c - newB == newB - a) || (xc > 0 && newC - b == b - a)) {
        cout << "YES\n";
    }
    else cout << "NO\n";
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