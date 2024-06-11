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
    map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    if (mp.size() == 1){
        cout << "NO";
    } else if (mp.size() == 2){
        cout << "YES\n";
        map<int, int> mp2;
        for (int i = 0; i < n; ++i){
            mp2[a[i]]++;
        }
        bool flag = false;
        for (auto &p : mp2){
            if (p.S == 1) flag = true;
        }
        if (flag){
            for (int i = 0; i < n; ++i){
                bool was = false;
                for (auto &pp : mp){
                    if (i == pp.S) was = true;
                }
                if (was) cout << 'R';
                else cout << 'B';
            }
        } else {
            for (int i = 0; i < n; ++i){
                if (i == mp.begin()->second) cout << 'R';
                else cout << 'B';
            }
        }
    } else{
        cout << "YES\n";
        for (int i = 0; i < n; ++i){
            if (i == mp.begin()->second) cout << 'R';
            else cout << 'B';
        }
    }

    cout << '\n';
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