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
    string s; cin >> s;
    
    int rIdx, mIdx;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') rIdx = i;
        else if (s[i] == 'M') mIdx = i;
    }

    cout << (rIdx < mIdx ? "Yes" : "No");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}