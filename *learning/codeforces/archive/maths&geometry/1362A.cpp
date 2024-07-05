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

int fck(int a){
    while (a % 2 == 0) a /= 2;
    return a;
}

void solve(){
    int a, b; cin >> a >> b;
    if (b > a) swap(a, b);

    if (fck(a) != fck(b)) cout << -1 << '\n';
    else {
        int k = a/b;
        int ans = 0;
        while (k != 1){
            if (k % 8 == 0) k /= 8;
            else if (k % 4 == 0) k /= 4;
            else k /= 2;
            ans++;
        }

        cout << ans << '\n';
    }
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