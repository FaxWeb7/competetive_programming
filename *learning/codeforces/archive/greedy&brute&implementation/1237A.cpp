#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

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
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int x = 1;
    for (int i = 0; i < n; ++i){
        if (a[i] % 2 == 0) cout << a[i]/2 << '\n';
        else {
            if (a[i] > 0) cout << (x ? (a[i] + 1)/2 : a[i]/2) << '\n';
            else cout << (x ? a[i]/2 : (a[i]-1)/2) << '\n';
            x = 1 - x;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}