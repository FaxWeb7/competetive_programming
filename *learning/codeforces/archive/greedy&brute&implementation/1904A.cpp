#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int a, b, xk, yk, xq, yq; cin >> a >> b >> xk >> yk >> xq >> yq;
    
    vi dy = {a, a, b, -b, -a, -a, b, -b};
    vi dx = {-b, b, a, a, -b, b, -a, -a};

    set<ii> st1, st2;
    for (int d = 0; d < dy.size(); ++d){
        st1.insert({yk + dy[d], xk + dx[d]});
        st2.insert({yq + dy[d], xq + dx[d]});
    }

    int res = 0;
    for (auto &p : st1){
        if (st2.find(p) != st2.end()) res++;
    }

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}