#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> table;
    for (int i = 0; i < n; i++){
        string input;
        vector<int> nums;

        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) nums.push_back(num);
        table.push_back(nums);
    }

    vector<int> trueCols;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (table[i][j] == x){
                trueCols.push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++){
        bool isOk = false;
        for (int j = 0; j < trueCols.size(); j++){
            if (trueCols[j] == i){
                isOk = true;
                break;
            }
        }
        cout << (isOk ? "YES" : "NO") << endl;
    }

    return 0;
}