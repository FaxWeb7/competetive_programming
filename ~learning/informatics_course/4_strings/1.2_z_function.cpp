#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }

    return z;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    string merged = pattern + '&' + text;
    vector<int> z = zFunction(merged);

    for (int i = 0; i <= merged.size(); ++i){
        if (z[i] == pattern.size()) cout << i-pattern.size()-1 << ' ';
    }

    return 0;
}