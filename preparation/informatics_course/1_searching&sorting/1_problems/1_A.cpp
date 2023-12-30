#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string inputArr;
    vector<int> arr;
    getline(cin, inputArr);
    stringstream ss(inputArr);
    int i;
    while (ss >> i){
        arr.push_back(i);
    }

    int x;
    cin >> x;

    int counter = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == x) counter++;
    }
    cout << counter;

    return 0;
}