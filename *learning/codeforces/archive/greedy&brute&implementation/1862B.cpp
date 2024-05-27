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
const int INF = 1e9;

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<int> a{b[0]};
        for (int i = 1; i < n; ++i){
            if (b[i-1] > b[i]){
                a.push_back(b[i]);
            }
            a.push_back(b[i]);
        }

        cout << a.size() << '\n';
        for (int &ai : a) cout << ai << ' ';
        cout << '\n';
    }

    return 0;
}