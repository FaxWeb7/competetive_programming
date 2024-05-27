#include <iostream>
#include <algorithm>
#include <vector>

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
    string n; cin >> n;
    int cnt = 0;
    for (char &c : n) {
        if (c == '4' || c == '7') cnt++;
    }

    bool res = true;
    for (char &c : to_string(cnt)){
        if (c != '4' && c != '7') res = false;
    }

    cout << (res ? "YES" : "NO");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}