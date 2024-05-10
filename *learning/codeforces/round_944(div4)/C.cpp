#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);

        int res = 0;
        for (int i = a; i < b; ++i)
            if (i == c || i == d) res++;

        if (res == 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
