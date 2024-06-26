#include <iostream>
#include <vector>
#include <set>
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
const int INF = 6;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;

        int sum = 0;
        for (int i = 0; i < n-1; ++i){
            int num; cin >> num;
            sum += num;
        }

        cout << -sum << '\n';
    }

    return 0;
}