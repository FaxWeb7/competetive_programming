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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

struct Compare {
    bool operator()(pii a, pii b){
        if (a.F < b.F || (a.F == b.F && a.S > b.S)) return true;
        return false;
    }
};

void solve(){
    int n, k; cin >> n >> k;
    priority_queue<pii, vector<pii>, Compare> pq;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num%k) pq.push({num%k, i+1});
        else cout << i+1 << ' ';
    }
    
    while (!pq.empty()){
        cout << pq.top().S << ' ';
        pq.pop();
    }

    cout << '\n';
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