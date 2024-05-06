#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

vector<int> testCase(int n, int k, vector<ii> &nums){
    vector<int> res;
    
    while (true){
    }

    return res;
}

int cmp(ii a, ii b){
    if (a.first > b.first){
        return 0;
    } else if (a.first == b.first && a.second < b.second){
        return 0;
    }
    return 1;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        int n, k;
        cin >> n >> k;
        vector<ii> nums(n);
        for (int i = 0; i < n; ++i) {
            int number;
            cin >> number;
            nums[i] = {number, i};
        }

        sort(nums.begin(), nums.end(), cmp);
        for (int &v : testCase(n, k, nums)) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}