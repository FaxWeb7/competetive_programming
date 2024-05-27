#include <iostream>
#include <vector>
#include <algorithm>

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
    int n; cin >> n;

    int res = 0;
    for (int _ = 0; _ < n; ++_){
        string t; cin >> t;
        if (t == "Tetrahedron") res += 4;
        else if (t == "Cube") res += 6;
        else if (t == "Octahedron") res += 8;
        else if (t == "Dodecahedron") res += 12;
        else res += 20;
    }

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}