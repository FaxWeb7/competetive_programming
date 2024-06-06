#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

bool good(vi a){
    int prevGcd = -1;
    for (int i = 0; i < a.size()-1; ++i){
        int curGcd = gcd(a[i], a[i+1]);
        if (curGcd < prevGcd) return false;
        prevGcd = curGcd;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vi a(n), b(n-1);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int prevGcd = -1;
    int delIdx = -1;
    for (int i = 0; i < n-1; ++i){
        int curGcd = gcd(a[i], a[i+1]);
        if (curGcd < prevGcd){
            delIdx = i;
            break;
        }
        prevGcd = curGcd;
    }

    if (delIdx == -1) {
        cout << "YES\n";
        return;
    } else {
        vi b0 = a, b1 = a, b2 = a;
        if (delIdx-1 >= 0) b0.erase(b0.begin() + delIdx-1);
        b1.erase(b1.begin() + delIdx);
        if (delIdx+1 < n) b2.erase(b2.begin() + delIdx+1);

        cout << (good(b0) || good(b1) || good(b2) ? "YES\n" : "NO\n");
    }
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