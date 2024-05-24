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


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        string unsortS = s;
        sort(all(s));
        map<char, int> r; //{symbol: index+1}
        int k = 0;
        for (int i = 0; i < n; ++i){
            if (!r[s[i]]) {
                r[s[i]] = ++k;
            }
        }

        string res = "";
        for (int i = 0; i < n; ++i){
            int revIdx = k-r[unsortS[i]]+1;
            char revChar;
            for (auto &p : r){
                if (p.second == revIdx) {
                    revChar = p.first;
                    break;
                }
            }
            res += revChar;
        }

        cout << res << '\n';
    }

    return 0;
}