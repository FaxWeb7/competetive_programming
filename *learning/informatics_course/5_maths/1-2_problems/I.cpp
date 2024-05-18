#include <iostream>

using namespace std;

int main(){
    int nDiv, kDiv;
    cin >> nDiv >> kDiv;
    
    int ans = 1;
    int n = nDiv+1, k = kDiv+1;
    while (n % nDiv != 0 || k % kDiv != 0){
        n++, k++, ans++;
    }

    cout << ans;

    return 0;
}