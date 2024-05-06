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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;

        int maxH = 0;
        pair<int, int> ans{0, 0}; // {height, width}
        for (int &height : heights){
            if (height >= ans.first) {
                if (ans.first * (ans.second+1) < height) {
                    ans.second++;
                } else {
                    ans.first = height;
                    ans.second = 1;
                }
            }
            maxH = max(maxH, height);
            s.push(height);
        }

        return (ans.first * ans.second > maxH ? ans.first * ans.second : maxH);
    }
};

int main(){
    vector<string> a = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout << s.evalRPN(a);

    return 0;
}