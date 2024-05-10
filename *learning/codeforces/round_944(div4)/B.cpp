#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        string s;
        cin >> s;

        bool yes = false;
        for (int i = 1; i < s.size(); ++i){
            if (s[i] != s[i-1]) {
                char t = s[i];
                s[i] = s[i-1];
                s[i-1] = t;
                yes = true;
                break;
            }
        }

        if (yes) cout << "YES\n" << s << '\n';
        else cout << "NO\n";
    }

    return 0;
}