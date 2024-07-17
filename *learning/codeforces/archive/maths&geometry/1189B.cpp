#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
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
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    sort(all(a));
    if (a[n-1] >= a[n-2] + a[n-3]) cout << "NO\n";
    else {
        reverse(all(a));
        swap(a[0], a[1]);
        
        cout << "YES\n";
        for (int i = 0; i < n; ++i){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}