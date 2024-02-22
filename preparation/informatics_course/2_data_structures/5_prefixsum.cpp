#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int>& prefix, int l, int r) {
    //[l, r]
    return prefix[r] - prefix[l-1];
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> prefix(nums.size()+1);

    prefix[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    cout << getSum(prefix, 2, 4);

    return 0;
}
