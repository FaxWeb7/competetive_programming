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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    vi a(4); cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(all(a));
    cout << a[3]-a[0] << ' ' << a[3]-a[1] << ' ' << a[3]-a[2] << '\n';
}

int32_t main(){
    solve();

    return 0;
}