#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct V {
    int x, y, z;
};

int main(){
    int n;
    cin >> n;

    vector<V> vec(n);
    for (int i = 0; i < n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        vec[i] = {x, y, z};
    }

    int totalX = 0, totalY = 0, totalZ = 0;
    for (auto &v : vec){
        totalX += v.x;
        totalY += v.y;
        totalZ += v.z;
    }

    if (totalX + totalY == 0 || totalY + totalZ == 0 || totalX + totalZ == 0) cout << "YES";
    else cout << "NO";

    return 0;
}