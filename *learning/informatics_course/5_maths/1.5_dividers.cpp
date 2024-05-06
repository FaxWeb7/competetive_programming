#include <iostream>
#include <vector>
using namespace std;

vector<int> dividers(int n){
    vector<int> res;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) {
                res.push_back(n / i);
            }
        }
    }

    return res;
}

int main(){
    for (int &n : dividers(8)) cout << n << ' ';

    return 0;
}