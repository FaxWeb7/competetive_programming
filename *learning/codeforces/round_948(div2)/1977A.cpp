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
#define int ll
const int INF = 1e9;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, m; cin >> n >> m;

        if (n == m) {
            cout << "Yes\n";
        } else if (m > n) {
            cout << "No\n";
        } else {
            if (n % 2 == m % 2){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}