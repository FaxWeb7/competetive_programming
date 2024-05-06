#include <iostream>
#include <vector>

using namespace std;

vector<int> getP(string &s){
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; ++i){
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
    string s;
    cin >> s;

    for (int &n : getP(s)) cout << n << ' ';

    return 0;
}