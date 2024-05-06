#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    int n, r, c;
    cin >> n >> r >> c;

    vector<int> hArr;
    hArr.reserve(n);
    for (int i = 0; i < n; i++){
        int height;
        cin >> height;
        hArr.push_back(height);
    }
    sort(hArr.begin(), hArr.end());
    
    // vector<int> mins;
    // mins.reserve(ceil(n/c));
    // for (int i = 0; i < n; i++){
    //     int maxV = INT_MIN;
    //     int minV = INT_MAX;
    //     for (int j = i; j < c+i; j++){
    //         if (hArr[j] > maxV) maxV = hArr[j];
    //         if (hArr[j] < minV) minV = hArr[j];
    //     }
    //     int difference = maxV - minV;

    // }

    return 0;
}