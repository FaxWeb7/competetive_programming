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
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vi a(n);
    for (int &x : a) cin >> x;

    priority_queue<int, vi, greater<int>> pq;
    int sum = 0;
    int mx = x+*max_element(all(a));
    for (int i = 0; i < n; ++i){
        if (mx - a[i] > 0) {
            pq.push(mx - a[i]);
            sum += mx - a[i];
        }
    }

    int cnt = 0;
    while (sum > x){
        int k = ((sum-x) + (pq.size()-1)) / pq.size();
        cnt += k;
        sum -= pq.size() * k;
        
        while (!pq.empty()){
            int val = pq.top();

            if (val-cnt <= 0) {
                sum += -(val-cnt);
                pq.pop();
            }
            else break;
        }
    }

    cout << mx-cnt << '\n';
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