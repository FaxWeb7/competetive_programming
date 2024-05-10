#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (auto &p : vec) cin >> p.first >> p.second;

    int curpos = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        pair<int, int> minPair = { -1, -1 };
        for (int j = 0; j < n; ++j){
            if (vec[j].first >= curpos && (vec[j].second < minPair.second || minPair.first == -1)){
                minPair = vec[j];
            }
        }
        
        if (minPair.first != -1) {
            ans++;
            curpos = minPair.second+1;
        }
    }

    cout << ans;

    return 0;
}