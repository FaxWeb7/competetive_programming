#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
#define int ll
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
    string n; cin >> n;
    string a = "", b = "";
    for (int i = 0; i < n.size()-1; ++i){
        a += '1';
        if (i == 0) b += '1';
        else b += '9';
    }
    a += '0';
    b += '8';

    if (n[n.size()-1] == '9') {
        cout << "NO\n";
        return;
    }
    
    bool flag = false;
    for (int i = n.size()-1; i >= 0; --i){
        if ((n[i] + '0') < (a[i] + '0')) flag = true;
        if ((n[i] + '0') > (b[i] + '0')) flag = true;
    }

    cout << (flag ? "NO" : "YES") << '\n';
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