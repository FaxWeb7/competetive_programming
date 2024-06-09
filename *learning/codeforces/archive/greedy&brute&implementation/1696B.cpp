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
    int n; cin >> n;
    vi a(n);

    bool correct = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 0) correct = false;
    }
    if (correct) {cout << 0 << '\n'; return;}

    bool start = false, finish = false;
    for (int i = 0; i < n; ++i){
        if (start && i-1 >= 0 && a[i-1] == 0 && a[i] != 0) finish = true;
        if (i+1 < n && a[i] != 0 && a[i+1] == 0) start = true;
    }
    cout << (start && finish ? 2 : 1) << '\n';
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