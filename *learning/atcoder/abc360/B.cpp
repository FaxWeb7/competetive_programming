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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    string s, t; cin >> s >> t;

    for (int k = 1; k < s.size(); ++k){
        vector<string> a;
        for (int start = 0; start < s.size(); start += k){
            string tempS = "";
            for (int i = start; i < start+k && i < s.size(); ++i) tempS += s[i];
            a.pb(tempS);
        }

        for (int guessIdx = 0; guessIdx < k; ++guessIdx){
            string guessStr = "";
            for (int i = 0; i < a.size(); ++i) {
                if (guessIdx < a[i].size()) guessStr += a[i][guessIdx];
            }
            if (guessStr == t) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}