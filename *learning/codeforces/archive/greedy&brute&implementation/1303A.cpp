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
    string s; cin >> s;

    vector<ii> a;
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == '1'){
            int l = i;
            while (i+1 < s.size() && s[i+1] == '1') ++i;
            a.push_back({l, i});
        }
    }

    int res = 0;
    if (a.size() != 0){
        for (int i = 0; i < a.size()-1; ++i){
            res += a[i+1].F - a[i].S - 1;
        }
    }

    cout << res << '\n';
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