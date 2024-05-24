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
const int INF = 1e9;


int main(){
    int t;
    cin >> t;
    while (t--){
        int x, y;
        cin >> x >> y;

        int ans = 0;
        while (x > 0 || y > 0) {
            if (y >= 2) x -= 7, y -= 2;
            else if (y == 1) x -= 11, y -= 1;
            else if (y <= 0) x -= 15;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}