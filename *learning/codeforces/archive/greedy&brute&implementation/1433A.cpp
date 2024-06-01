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
    string x; cin >> x;

    int res = 0;

    string a = "";
    char add = '1';
    while (a != x) {
        if (!a.size() || stoi(a) < 10000) {
            a += add;
        } else {
            add += 1;
            a = "";
        }

        if (a.size() && stoi(a) < 10000) res += a.size();
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