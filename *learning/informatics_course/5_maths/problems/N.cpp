#include <iostream>
#include <map>
using namespace std;

map<int, int> factorize(int n){
    map<int, int> res;
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0){
            n /= i;
            res[i]++;
        }
    }

    if (n > 1) res[n]++;

    return res;
}

int main(){
    int n;
    cin >> n;

    string ans = "";
    for (auto &[x, times] : factorize(n)){
        if (times > 1) ans += to_string(x) + '^' + to_string(times) + '*';
        else ans += to_string(x) + '*';
    }
    cout << ans.substr(0, ans.size()-1);

    return 0;
}