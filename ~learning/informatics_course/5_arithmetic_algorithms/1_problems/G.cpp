#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool> isPrime(n+1, true);
    for (int i = 2; i * i <= n; ++i){
        if (isPrime[i]){
            for (int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    unordered_set<int> nums;
    for (int i = 1; i <= n; ++i){
        if (isPrime[i]){
            if (nums.find(n-i) != nums.end()){
                cout << i << ' ' << n-i;
                break;
            }
            nums.insert(i);
        }
    }

    return 0;
}