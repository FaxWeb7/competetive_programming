#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;
#define int ll
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

int ap(int a1, int an){
    return ((a1 + an) * (an - a1 + 1)) / 2;
}

void solve(){
    int n, x, y; cin >> n >> x >> y;

    int sumX = ap(n - n/x + 1, n);

    int sumY = 0;
    sumY += ap(n - n/x + 1 + 0, n - n/x + 1 + (n/lcm(x,y)-1));
    sumY += ap(1, (n / y) - (n / lcm(x, y)));

    cout << sumX - sumY << '\n';
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