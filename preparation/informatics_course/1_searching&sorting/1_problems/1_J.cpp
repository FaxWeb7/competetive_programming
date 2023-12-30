#include <iostream>
#include <sstream>
#include <string>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);
    stringstream ss(input);

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int num;
    while (ss >> num){
        if (num > max1){
            max2 = max1;
            max1 = num;
        }
        else if (num > max2 && num != max1){
            max2 = num;
        }
    }

    cout << max2;
    
    return 0;
}