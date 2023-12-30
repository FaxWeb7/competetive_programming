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

    int maxV = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > maxV){
            maxV = arr[i];
        }
    }

    cout << maxV;
    
    return 0;
}