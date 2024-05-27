#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;


int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<vc> res(n, vc(m));
    int q = 2;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (i % 2 == 0) cout << '#';
            else if ((j == m-1 && q == 2) || (j == 0 && q == 1)) cout << '#';
            else cout << '.';

        }
        if (i % 2) q = 3 - q;
        cout << '\n';
    }

    return 0;
}