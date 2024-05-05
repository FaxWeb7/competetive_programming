#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool canSayHello(string s) {
    string target = "hello";
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == target[j]) {
            j++;
        }
        if (j == target.length()) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    if (canSayHello(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
