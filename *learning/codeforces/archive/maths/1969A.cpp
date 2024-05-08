#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[51] = {0};
        int ans = 3;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[a[i]]==i) ans=2;
        } 
        cout << ans << endl;
    }
} 