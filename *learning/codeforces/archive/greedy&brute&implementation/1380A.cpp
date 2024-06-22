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
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    int n; cin >> n;
    vi p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int a = -1, b = -1, c = -1;
    for (int i = 0; i < n; ++i){
        if (a == -1 && i < n-1 && p[i] < p[i+1]) {
            a = i;
            b = i+1;
        } else if (b != -1 && p[b] < p[i]){
            b = i;
        } else if (a != -1 && b != -1 && p[b] > p[i]){
            c = i;
            cout << "YES\n";
            cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
            return;
        }
    }

    cout << "NO\n";
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