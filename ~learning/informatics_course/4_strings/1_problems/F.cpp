#include <iostream>
#include <vector>

using namespace std;

int countMaxPalindrome(string &s, int mid){
    int n = s.size();
    int res = 1;

    if (mid >= ((n + 1) / 2)) {
        reverse(s.begin(), s.end());
        mid = n - mid - 1;
    }

    int right = 2*mid;
    for (int i = 0; i <= right; ++i){
        if (s[i] != s[right-i]) continue;
        if (i == right) res = i+1;
    }

    return res;
}

int main(){
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i){
        cout << countMaxPalindrome(s, i) << ' ';
    }

    return 0;
}