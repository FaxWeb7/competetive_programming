#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

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
const int INF = 1e9;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    if (n == 1) {
        char ch; cin >> ch;
        cout << 1;
        return;
    }
    string d; cin >> d;

    set<string> was;
    set<string> st;
    st.insert(d);

    int res = 0;
    while (!st.empty()){
        string s = *st.begin();
        for (int start = 0; start < s.size()-2; ++start){
            if (s[start] == 'A' && s[start+1] == 'B' && s[start+2] == 'A') {
                string t = s.substr(0, start) + 'A';
                if (start + 3 < s.size()) t += s.substr(start + 3, s.size()-(start+3));
                if (!was.count(t)){
                    res = (res + 1) % MOD;
                    was.insert(t);
                    st.insert(t);
                }
            }
            if (s[start] == 'B' && s[start+1] == 'A' && s[start+2] == 'B') {
                string t = s.substr(0, start) + 'B';
                if (start + 3 < s.size()) t += s.substr(start + 3, s.size()-(start+3));
                if (!was.count(t)){
                    res = (res + 1) % MOD;
                    was.insert(t);
                    st.insert(t);
                }
            }
        }
        st.erase(s);
    }

    cout << (res % MOD) + 1;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}