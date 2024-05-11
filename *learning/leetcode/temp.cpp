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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (int i = 1; i < nums.size()-1; ++i){
            int l = 0, r = nums.size()-1;
            while (l < r && l < i && r > i){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    if (find(res.begin(), res.end(), vector<int>{nums[l], nums[i], nums[r]}) == res.end()){
                        res.push_back({nums[l], nums[i], nums[r]});
                    }
                    l++;
                }
                else if (sum > 0) r--;
                else l++;
            }
        }

        return res;
    }
};

int main(){
    vector<int> a = {0, 0, 0, 0};
    Solution s;
    for (auto &row : s.threeSum(a)){
        for (int &n : row) cout << n << ' ';
        cout << '\n';
    }

    return 0;
}