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
    vector<int> arr;
    getline(cin , input);
    stringstream ss(input);
    int i;
    while (ss >> i){
        arr.push_back(i);
    }

    int x;
    cin >> x;

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            ans.push_back(i+1);
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }

    return 0;
}