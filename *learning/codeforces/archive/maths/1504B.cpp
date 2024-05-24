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
        string a, b; cin >> a >> b;

        a += '0', b += '0';
        bool isNo = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] == '1') cnt++;
            else cnt--;

            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0){
                cout << "NO\n";
                isNo = true;
                break;
            }
        }

        if (!isNo) cout << "YES\n";
    }

    return 0;
}