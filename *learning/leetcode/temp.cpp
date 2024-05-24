#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<string, int> si;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> mp;
        for (int l = 0, r = 0; l < s.size(); ++l){
            int curLen = 0;
            while (!mp[s[r]]){
                mp[s[r]] = 1;
                curLen++, r++;
            }

            maxLen = max(maxLen, curLen);
            mp[s[l]] = 0;
        }

        return maxLen;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
    vector<int> a = {0, 0, 0, 0};
    Solution s;

    return 0;
}