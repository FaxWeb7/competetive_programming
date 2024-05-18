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
    bool check(vector<int> &piles, int targetH, int m){
        int curH = 0;
        for (int &pile : piles){
            curH += ceil((double)pile / m);
        }

        return curH <= targetH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[max_element(piles.begin(), piles.end()) - piles.begin()];
        while (l < r){
            int m = (r + l) / 2;
            if (check(piles, h, m)) r = m;
            else l = m + 1;
        }

        return l;
    }
};

int main(){
    vector<int> a = {0, 0, 0, 0};
    Solution s;

    return 0;
}