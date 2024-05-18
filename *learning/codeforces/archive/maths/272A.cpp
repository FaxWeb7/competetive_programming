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
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    n++;

    int res = 0;
    for (int i = 1; i <= 5; ++i){
        if ((sum + i) % n != 1) res++;
    }

    cout << res << '\n';

    return 0;
}