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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r){
            if (numbers[l] + numbers[r] == target) break;
            
            if (numbers[l] + numbers[r] < target) l++;
            else r--;
        }

        return {l+1, r+1};
    }
};

int main(){
    vector<string> a = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;

    return 0;
}