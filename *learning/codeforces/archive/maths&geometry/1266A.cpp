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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    string s; cin >> s;

    bool even = false, zero = false;
    int sum = 0;
    for (char &ch : s) {
        int x = ch - '0';
        if (x % 2 == 0) {
            if (x == 0 && !zero) zero = true;
            else even = true;
        }

        sum += x;
    }

    cout << (sum % 3 == 0 && even && zero ? "red\n" : "cyan\n");
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