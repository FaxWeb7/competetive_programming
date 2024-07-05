#include <iostream>
#include <vector>

using namespace std;

int main(){
    uint32_t h = 0;
    h <<= 31;
    cout << h;
    int n = 50;

    vector<bool> isPrime(n, true);
    for (int i = 2; i * i < n; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
    }

    cout << "Prime numbers: \n";
    for (int i = 2; i < n; ++i){
        if (isPrime[i]) cout << i << ' ';
    } 

    return 0;
}