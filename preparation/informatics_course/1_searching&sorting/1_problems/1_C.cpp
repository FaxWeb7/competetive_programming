#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string input;
    vector<int> arr;
    getline(cin, input);
    stringstream ss(input);
    int i;
    while (ss >> i){
        arr.push_back(i);
    }

    int x;
    cin >> x;

    int ans;
    int minDiff = INT_MAX;
    for (int i = 0; i < n; i++){
        int diff = abs(arr[i]-x);
        if (diff < minDiff){
            ans = arr[i];
            minDiff = diff;
        }
    }

    cout << ans;

    return 0;
}