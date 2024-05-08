#include <iostream>
#include <cmath>
using namespace std;

struct V {
    int sum, first, second;
};

bool operator<(const V a, const V b){
    return a.sum < b.sum;
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<V> res;
    if (a > 0 && c > 0){
        res.push_back({a+1 + c+1, a+1, c+1});
    }
    if (b > 0 && d > 0){
        res.push_back({b+1 + d+1, b+1, d+1});
    }
    if (a > 0 && b > 0){
        res.push_back({max(a, b) + 1 + 1, max(a, b) + 1, 1});
    }
    if (c > 0 && d > 0){
        res.push_back({max(c, d) + 1 + 1, 1, max(c, d) + 1});
    }
    sort(res.begin(), res.end());

    cout << res[0].first << ' ' << res[0].second;

    return 0;
}