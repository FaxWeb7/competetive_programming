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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int maxIdx = (a[0] >= a[1] ? 0 : 1);
    int minIdx = (a[1] <= a[0] ? 1 : 0);
    for (int i = 0; i < n; ++i){
        if (a[i] > a[maxIdx]) maxIdx = i;
        if (a[i] <= a[minIdx]) minIdx = i;
    }

    cout << (maxIdx > minIdx ? maxIdx-1 + n-minIdx - 1 : maxIdx-1 + n-minIdx);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}