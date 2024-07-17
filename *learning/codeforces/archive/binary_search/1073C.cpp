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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int x, y; cin >> x >> y;

    int fx = 0, fy = 0;
    for (char &ch : s){
        if (ch == 'U') fy++;
        else if (ch == 'D') fy--;
        else if (ch == 'L') x--;
        else x++;
    }
    
    if (abs(fx) < abs(x) && abs(fy) < abs(y)) {cout << -1; return;}
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}