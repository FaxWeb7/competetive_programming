#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int n){
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int target;
    cin >> target;

    set<int> s;
    for (int i = 4; i < target; i++){
        if (isPrime(i)) continue;
        if (s.find(target - i) != s.end()){
            cout << target - i << ' ' << i;
            break;
        }
        s.insert(i);
    }

    return 0;
}