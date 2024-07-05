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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 10000;

void solve(){
    string s, t; cin >> s >> t;

    string startS = s, startT = t;
    int cnt = 0;
    while (s != t && cnt < INF){
        if (s.size() < t.size()){
            s += startS;
        } else t += startT;
        cnt++;
    }

    cout << (cnt == INF ? "-1" : s) << '\n';
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