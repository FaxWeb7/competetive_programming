#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

ll getSum(vector<ll>& prefixSums, int left, int right) {
    return prefixSums[right] - prefixSums[left - 1]; 
}

int main() {
    int N, K;
    cin >> N;
    vector<ll> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<ll> prefixSums;
    prefixSums.resize(N + 1);
    prefixSums[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
    }

    cin >> K;
    vector<ll> ans(K);
    for (int i = 0; i < K; i++) {
        int left, right;
        cin >> left >> right;
        ans[i] = getSum(prefixSums, left, right);
    }

    for (int i = 0; i < K; i++) cout << ans[i] << endl;

    return 0;
}
