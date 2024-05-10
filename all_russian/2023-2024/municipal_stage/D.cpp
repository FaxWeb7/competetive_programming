#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> l(n), r(m);
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < m; ++i) cin >> r[i];

    vector<pair<int, int>> res;
    int i = 0, j = 0;
    while (i < n){
        if (j < m && l[i] >= r[j]){
            res.push_back({ (l[i] - r[j]) / 2, l[i] - ((l[i] - r[j]) / 2) });
            i++, j++;
        } else {
            res.push_back({ 0, l[i] });
            i++;
        }
    }

    while (j < m){
        res.push_back({ 0, r[j] });
        j++;
    }

    for (auto &p : res){
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}