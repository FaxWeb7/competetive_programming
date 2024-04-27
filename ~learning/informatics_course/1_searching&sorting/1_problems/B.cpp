#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> arr;
    int i;
    while (ss >> i){
        arr.push_back(i);
    }

    int x;
    cin >> x;

    bool ans = false;
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            ans = true;
            break;
        }
    }

    cout << (ans==true ? "YES" : "NO");

    return 0;
}