#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);

        int sum = 0;
        for (int &num : v) {
            cin >> num;
            sum += num;
        }
        
        int ans = 0;
        while (sum != n){
            int x = (n+1) - sum;
            if (x > 0) sum += x;
            ans++, n++;
        }

        cout << ans << '\n';
    }

    return 0;
}