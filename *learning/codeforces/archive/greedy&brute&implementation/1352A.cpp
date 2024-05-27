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
        string n; cin >> n;

        vector<string> res;
        for (int i = 0; i < n.size(); ++i){
            if (n[i] != '0'){
                string t;
                t += n[i];
                for (int j = 0; j < n.size()-i-1; ++j) t += '0';
                res.push_back(t);
            }
        }

        cout << res.size() << '\n';
        for (string &k : res) cout << k << ' ';
        cout << '\n';
    }

    return 0;
}