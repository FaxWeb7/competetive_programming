#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    int n, k; cin >> n >> k;
    deque<int> dq;
    for (int i = 0; i < n*k; ++i) {
        int num; cin >> num;
        dq.push_back(num);
    }

    int res = 0;
    while (!dq.empty()){
        for (int i = 0; i < n/2; ++i) dq.pop_back();
        res += dq.back();
        dq.pop_back();
        for (int i = 0; i < (n % 2 ? n/2 : (n/2)-1); ++i) dq.pop_front();
    }

    cout << res << '\n';
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
