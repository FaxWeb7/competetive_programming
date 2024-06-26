#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
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
const ld EPS = 1e-9;

void solve(){
    string n; cin >> n;
    
    pii cnt1 = {-1, -1}, cnt2 = {-1, -1};
    for (int i = n.size()-1; i >= 0; --i){
        if (n[i] == '0'){
            if (cnt1.F == -1) cnt1.F = i;
            else if (cnt1.S == -1) cnt1.S = i;
        }
        if (n[i] == '5'){
            if (cnt1.F != -1 && cnt1.S == -1) cnt1.S = i;
            if (cnt2.F == -1) cnt2.F = i;
        }
        if (n[i] == '2' && cnt2.F != -1 && cnt2.S == -1) cnt2.S = i;
        if (n[i] == '7' && cnt2.F != -1 && cnt2.S == -1) cnt2.S = i;
    }

    if (cnt1.F == -1 || cnt1.S == -1){
        cout << (n.size() - cnt2.F - 1) + (cnt2.F - cnt2.S - 1) << '\n';
    } else if (cnt2.F == -1 || cnt2.S == -1){
        cout << (n.size() - cnt1.F - 1) + (cnt1.F - cnt1.S - 1) << '\n';
    } else {
        cout << min((n.size() - cnt1.F - 1) + (cnt1.F - cnt1.S - 1), (n.size() - cnt2.F - 1) + (cnt2.F - cnt2.S - 1)) << '\n';
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