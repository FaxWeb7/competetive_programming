#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;

    ll i = 1;
    ll j = 1;
    ll count = 0;
    ll last = 1;
    while(count < x) {
        while (count < x && i * i > j * j * j) { 
            last = j * j * j;
            ++j;
            ++count;
        }
        while (count < x && i * i == j * j * j) { 
            last = i * i;
            ++i;
            ++j;
            ++count;
        }
        while (count < x && i * i < j * j * j) { 
            last = i * i;
            ++i;
            ++count;
        }
    }
    cout<< last <<endl;


    return 0;
}