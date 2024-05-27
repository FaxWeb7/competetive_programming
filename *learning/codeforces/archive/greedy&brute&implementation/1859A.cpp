#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
#define int ll
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vi b{a[0]}, c;
    bool needC = true;
    for (int i = 1; i < n; ++i){
        if (needC){
            bool ok = true;
            for (int j = 0; j < b.size(); ++i){
                if (b[j] % a[i] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                c.push_back(a[i]);
                needC = false;
            }
        }
        else b.push_back(a[i]);
    }

    if (c.size() == 0) cout << -1 << '\n';
    else {
        cout << b.size() << ' ' << c.size() << '\n';
        for (int k : b) cout << k << ' ';
        cout << '\n';
        for (int k : c) cout << k << ' ';
        cout << '\n';
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