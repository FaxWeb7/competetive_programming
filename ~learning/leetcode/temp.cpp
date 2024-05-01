#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> res(temperatures.size());
        for (int i = temperatures.size()-1; i >= 0; --i){
            while (!stack.empty() && stack.top().first <= temperatures[i]){
                stack.pop();
            }

            if (!stack.empty()){
                res[i] = stack.top().second - i;
            }
            stack.push({temperatures[i], i});
        }

        return res;
    }
};

int main(){
    stack<int> s;
    int a, b, x;
    cin >> a >> b >> x;
    Solution sol;
    vector<int> c = {a, b, x};
    sol.dailyTemperatures(c);

    return 0;
}