#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    set<ll> numSet;
    for (int i = 0; i < n; i++){
        ll num;
        cin >> num;
        numSet.insert(num);
    }

    cout << numSet.size();

    return 0;
}