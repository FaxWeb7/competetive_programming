#include <iostream>
#include <vector>

using namespace std;

vector<int> prefixFunction(string &s){
    int n = s.size();
    vector<int> p(n);

    for (int i = 1; i < n; ++i) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0){
            cur = p[cur - 1];
        }

        if (s[i] == s[cur]){
            p[i] = cur + 1;
        }
    }

    return p;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    string merged = pattern + '&' + text;
    vector<int> p = prefixFunction(merged);

    for (int i = 0; i < merged.size(); ++i){
        if (p[i] == pattern.size()){
            cout << i - pattern.size()*2 << ' ';
        }
    }

    return 0;
}