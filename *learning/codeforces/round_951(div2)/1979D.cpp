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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    for (int i = n-1; i >= 0; --i){
        if (s[i] != s[n-1]) break;
        cnt++;
    }

    auto operation = [&](int p){
        reverse(s.begin(), s.begin() + p);
        s = s.substr(p, s.size()) + s.substr(0, p);

        for (int i = 0; i+1 < k; ++i){
            if (s[i] != s[i+1]) return false;
        }
        for (int i = 0; i+k < n; ++i){
            if (s[i+k] == s[i]) return false;
        }
        return true;
    };
    
    if (cnt > k) {
        cout << -1 << '\n';
    } else if (cnt == k){
        
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