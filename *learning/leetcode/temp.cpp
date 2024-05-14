#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto asd = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return asd;
    }
};

int main(){
    vector<int> a = {0, 0, 0, 0};
    Solution s;

    return 0;
}