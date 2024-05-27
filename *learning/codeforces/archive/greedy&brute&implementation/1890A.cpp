#include <iostream>
#include <vector>
#include <unordered_map>
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
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            mp[num]++;
        }

        if (mp.size() > 2) {
            cout << "NO\n";
        }
        else if (mp.size() == 1){
            cout << "YES\n";
        }
        else if (mp.size() == 2){
            bool isOk = false;
            for (auto &p : mp){
                if (p.second == n/2) {
                    cout << "YES\n";
                    isOk = true;
                    break;
                }
            }
            if (!isOk) cout << "NO\n";
        }
    }

    return 0;
}