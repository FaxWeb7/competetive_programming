#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

bool isPrime(int n){
    for (int i = 2; i*i <= n; ++i){
        if (n%i == 0) return false;
    }
    return true;
}

int sol(int n){
    if (isPrime(n) || n == 2) return 1;

    int nearPrime = n-2;
    while (!isPrime(nearPrime)) nearPrime--;

    return 1 + sol(n-nearPrime);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    if (isPrime(n)) cout << 1;
    else if (n % 2 == 0) cout << 2;
    else if (n % 2 == 1 && isPrime(n-2)) cout << 2;
    else cout << 3;

    return 0;
}