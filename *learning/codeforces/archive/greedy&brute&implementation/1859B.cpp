#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<pqi> a(n);
    for (int i = 0; i < n; ++i){
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int num; cin >> num;
            a[i].push(num);
        }
    }

    int minFirst = INF;
    for (int i = 0; i < n; ++i){
        minFirst = min(minFirst, a[i].top());
        a[i].pop();
    }

    int minSecond = INF;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        sum += a[i].top();
        minSecond = min(minSecond, a[i].top());
        a[i].pop();
    }
    
    cout << minFirst + (sum - minSecond) << '\n';
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