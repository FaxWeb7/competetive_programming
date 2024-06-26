#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
    int n; cin >> n;

    long double res = 0.0;
    for (int i = n; i >= 1; --i){
        res += (1.0 / (double)i);
    }

    cout << fixed << setprecision(10) << res;

    return 0;
}