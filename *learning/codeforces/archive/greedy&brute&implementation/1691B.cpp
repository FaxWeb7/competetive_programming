#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    map<int, vi> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }

    bool ok = true;
    for (auto &p : mp){
        if (p.S.size() == 1) ok = false;
    }

    if (!ok || n == 1) cout << -1 << '\n';
    else {
        for (auto &p : mp){
            vi vec = p.S;
            if (vec.size() % 2 == 0){
                for (int i = vec[vec.size()-1]; i >= vec[0]; --i) cout << i << ' ';
            } else {
                cout << vec[vec.size()-1] << ' ';
                for (int i = vec[0]; i < vec[vec.size()-1]; ++i) cout << i << ' ';
            }
        }
        cout << '\n';
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