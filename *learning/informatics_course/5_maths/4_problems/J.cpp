#include <iostream>
using namespace std;

void solve(int n, string cur){
    if (cur.size() == n){
        cout << cur << '\n';
    }
    else{
        solve(n, cur + '0');
        solve(n, cur + '1');
    }
}

int main(){
    int n;
    cin >> n;

    solve(n, "");

    return 0;
}