#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int sum = 0;
    for (char &symbol : s){
        sum += symbol - '0';
    }

    cout << (sum % 3 == 0 ? "YES" : "NO");

    return 0;
}