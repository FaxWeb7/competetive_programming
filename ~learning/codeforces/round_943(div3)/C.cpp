#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> testCase(vector<int> &x, int n){
    vector<int> a(n);
    a[0] = x[0]+1;
    
    for (int i = 1; i < n; ++i){
        int j = 1;
        while (j <= 10E9){
            if (x[i - 1] == j % a[i - 1]) break;
            j++;
        }
        a[i] = j;
    }

    return a;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        int n;
        cin >> n;
        vector<int> x(n-1);
        for (int j = 0; j < n-1; ++j) cin >> x[j];

        for(int &n : testCase(x, n)) {
            cout << n << ' ';
        }
        cout << '\n';
    }

    return 0;
}