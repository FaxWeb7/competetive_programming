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
    int n; cin >> n;

    int height = 0;
    int volume = 0;
    int prev = 0;
    while (volume + prev + height <= n){
        volume = volume + prev + height;
        prev += height;
        height++;
    }

    cout << height-1;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}