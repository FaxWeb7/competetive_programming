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
    while (ss >> i) arr.push_back(i);

    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (int i = 0; i < n; i++){
        if (arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2){
            min2 = arr[i];
        }
    }

    cout << min1 << ' ' << min2;

    return 0;
}