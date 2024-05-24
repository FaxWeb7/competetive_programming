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
        int n, k;
        cin >> n >> k;
        
        int prevNum = -1;
        bool isSorted = true;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (prevNum != -1 && prevNum > num) isSorted = false;
            prevNum = num; 
        }
        
        if (k == 1 && !isSorted) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}