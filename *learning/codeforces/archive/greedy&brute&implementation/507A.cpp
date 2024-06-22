#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
// #define int ll
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
    int n, k; cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < n; ++i){
        int num; cin >> num;
        q.push({num, i+1});
    }

    vi res;
    while (!q.empty()){
        pii p = q.top();
        q.pop();
        k -= p.F;
        if (k >= 0) res.push_back(p.S);
    }
    
    cout << res.size() << '\n';
    for (int &num : res) cout << num << ' ';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}