#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int testCase(int n, vector<int> &a, vector<int> &b){
    for (int i = 0; i < n; ++i){
        int crashI = -1;
        for (int j = 0; j < n; j++){
            if (a[j] > b[j]) {
                crashI = j;
                break;
            }
        }

        if (crashI == -1) return i;
        a.push_back(b[crashI]);
        sort(a.begin(), a.end());
        a.pop_back();
    }

    return 0;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &num : a) cin >> num;
        vector<int> b(n);
        for (int &num : b) cin >> num;

        cout << testCase(n, a, b) << '\n';
    }

    return 0;
}