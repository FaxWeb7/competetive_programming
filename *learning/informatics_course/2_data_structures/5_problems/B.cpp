#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

struct PrefixItem {
    ll value;
    int countL;
    PrefixItem(ll value, int countL) : value(value), countL(countL) {};
};

PrefixItem getPrefixData(vector<PrefixItem>& prefixes, int l, int r){
    return {prefixes[r].value - prefixes[l-1].value, prefixes[r].countL + prefixes[l-1].countL};
}

int main() {
    int n, L, C;
    cin >> n >> L >> C;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<PrefixItem> prefixes(n+1, {0,0});
    for (int i = 1; i <= n; i++){
        int isLess = nums[i-1] < 0 ? 1 : 0;
        prefixes[i] = {prefixes[i-1].value + nums[i-1], isLess + prefixes[i-1].countL};
    }

    ll maxRes = 0;
    for (int left = 1; left <= (n+1)/2; left++){
        int right = left+L-1;
        PrefixItem data = getPrefixData(prefixes, left, right);
        if (data.countL <= C && data.value > maxRes) maxRes = data.value; 
    }

    cout << maxRes;

    return 0;
}