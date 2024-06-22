#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
#define int ll
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
    int n, x; cin >> n >> x;

    int maxVal = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        maxVal += ceil((double)num/x);
        sum += num;
    }

    cout << (int)ceil((double)sum/x) << ' ' << (int)maxVal << '\n';
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