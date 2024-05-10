#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        string s;
        cin >> s;

        bool wasMid = false;
        int res = 1;
        for (int i = 1; i < s.size(); ++i){
            if (s[i] != s[i-1]){
                if (s[i] == '1' && s[i-1] == '0' && wasMid == false){
                    wasMid = true;
                } else {
                    res++;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}