#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    string vowel = "aoyeui";
    for (char &c : s){
        c = tolower(c);
        if (vowel.find(c) == -1) cout << '.' << c;
    }

    return 0;
}