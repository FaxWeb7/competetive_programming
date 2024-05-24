#include <iostream>
#include <vector>
#include <map>
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


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        map<pair<int, ii>, int> gen;
        map<ii, int> mp1, mp2, mp3;

        ll ans = 0;
        for (int i = 0; i < n - 2; ++i){
            int val = gen[{a[i], {a[i + 1], a[i + 2]}}];

            ans += mp1[{a[i], a[i+1]}] - val;
            ans += mp2[{a[i], a[i+2]}] - val;
            ans += mp3[{a[i+1], a[i+2]}] - val;

            gen[{a[i], {a[i + 1], a[i + 2]}}]++;
            mp1[{a[i], a[i+1]}]++;
            mp2[{a[i], a[i+2]}]++;
            mp3[{a[i+1], a[i+2]}]++;
        }

        cout << ans << '\n';
    }
    return 0;
}
