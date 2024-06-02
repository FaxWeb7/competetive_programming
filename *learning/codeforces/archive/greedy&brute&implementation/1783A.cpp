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

void solve(){
    int n; cin >> n;

    vi a(n);
    bool isSame = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] != a[i-1]) isSame = false;
    }

    if (isSame) {
        cout << "NO\n";
        return;
    }

    reverse(all(a));
    if (a[0] == a[1]){
        int j = 2;
        while (a[1] == a[j]) ++j;
        swap(a[1], a[j]);
    }

    cout << "YES\n";
    for (auto i : a) cout << i << ' ';
    cout << '\n';
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