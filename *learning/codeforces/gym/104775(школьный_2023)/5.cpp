#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
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
const int INF = 2e14 + 1;
const int MOD = 1e9 + 7;

struct Vertex {
    int red, green, time;
    Vertex() : red(0), green(0), time(0) {}
};

void solve(){
    int y; cin >> y;
    if (y == 23) y = 1;
    else if (y == 34) y = 2;
    else y = 3;
    vector<Vertex> a(4);
    for (auto &v : a) cin >> v.red >> v.green >> v.time;

    int ans1 = 0;
    int x = 0;
    int i = 0;
    while (i != y) {
        if (a[i].green < a[i].time) {
            ans1 = INF;
            break;
        }

        int val;
        if (x % (a[i].red + a[i].green) <= a[i].red) {
            val = (a[i].red - (x % (a[i].red + a[i].green))) + a[i].time;
        } else {
            if ((a[i].red + a[i].green) - (x % (a[i].red + a[i].green)) >= a[i].time){
                val = a[i].time;
            } else {
                val = ((a[i].red + a[i].green) - (x % (a[i].red + a[i].green))) + a[i].red + a[i].time;
            }
        }
        ans1 += val;
        x += val;

        if (i == 0) i = 3;
        else i--;
    }

    int ans2= 0;
    x = 0;
    i = 1;
    while (i-1 != y) {
        if (a[i].green < a[i].time) {
            ans2 = INF;
            break;
        }

        int val;
        if (x % (a[i].red + a[i].green) <= a[i].red) {
            val = (a[i].red - (x % (a[i].red + a[i].green))) + a[i].time;
        } else {
            if ((a[i].red + a[i].green) - (x % (a[i].red + a[i].green)) >= a[i].time){
                val = a[i].time;
            } else {
                val = ((a[i].red + a[i].green) - (x % (a[i].red + a[i].green))) + a[i].red + a[i].time;
            }
        }
        ans2 += val;
        x += val;

        i++;
    }

    cout << min(ans1, ans2);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}