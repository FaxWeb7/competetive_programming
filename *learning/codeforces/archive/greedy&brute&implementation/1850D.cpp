#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    sort(all(a));
    int maxLen = 1;
    int curLen = 1;
    for (int i = 0; i < n-1; ++i){
        if (a[i+1]-a[i] <= k) curLen++;
        else curLen = 1;
        maxLen = max(maxLen, curLen);
    }

    cout << n-maxLen << '\n';
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