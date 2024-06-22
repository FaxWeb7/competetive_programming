#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    string s; cin >> s;
    int n = s.size();

    int res = 0;

    bool ok = true;
    while (ok){
        ok = false;
        for (int i = 0; i < n-1; ++i){
            if (s[i] != s[i+1]){
                res++;
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                n -= 2;
                ok = true;
                break;
            }
        }
    }

    cout << (res % 2 ? "DA\n" : "NET\n");
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