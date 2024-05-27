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
    int plus = 0, minus = 0;
    for (int i = 0; i < n; ++i){
        int num; cin >> num;
        if (num == 1) plus++;
        else minus++;
    }

    int ans = 0;
    while (plus < (n+1)/2 || minus % 2){
        plus++, minus--, ans++;
    }

    cout << ans << '\n';
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