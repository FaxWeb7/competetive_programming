#include <iostream>
using namespace std;

int countC1(int& k, int i){
    int c = 0;
    while (k%i == 0){
        k /= i;
        c++;
    }
    return c;
}

int countC2(int n, int i){
    int c = 0;
    while (n / i > 0){
        c += n/i;
        n /= i;
    }
    return c;
}

int main(){
    int n, k;
    cin >> n >> k;

    int result = 1E9;
    for (int i = 2; i <= k; i++){
        if (k%i == 0){
            int c1 = countC1(k, i);
            int c2 = countC2(n, i);
            result = (result < c2/c1 ? result : c2/c1);
        }
    }
    cout << result;

    return 0;
}
