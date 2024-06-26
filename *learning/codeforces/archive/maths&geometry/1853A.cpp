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
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    bool isSorted = true;
    for (int i = 0; i < n-1; ++i){
        if (a[i] > a[i+1]) isSorted = false;
    }
    
    if (!isSorted) cout << 0 << '\n';
    else {
        int diff = abs(a[0]-a[1]);
        for (int i = 1; i < n-1; ++i){
            diff = min(diff, abs(a[i]-a[i+1]));
        }
        cout << diff/2 + 1 << '\n';
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