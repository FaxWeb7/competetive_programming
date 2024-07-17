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
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = hypot(abs(x1-x2), abs(y1-y2));
    double b = hypot(abs(x2-x3), abs(y2-y3));
    double c = hypot(abs(x1-x3), abs(y1-y3));
    if (abs(c*c - (a*a + b*b)) < 1e-2 || abs(a*a - (c*c + b*b)) < 1e-2 || abs(b*b - (a*a + c*c)) < 1e-2) cout << "Yes";
    else cout << "No";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}