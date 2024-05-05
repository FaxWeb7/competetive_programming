#include <iostream>
#include <vector>

using namespace std;

vector<int> factorize(int n){
    vector<int> res;
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0) {
            n /= i;
            res.push_back(i);
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

int main(){
    int n;
    cin >> n;

    for (int &n : factorize(n)){
        cout << n << ' ';
    }
}