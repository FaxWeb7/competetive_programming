#include <iostream>

using namespace std;

int testCase(int x){
    pair<int, int> maxY = {1, 1}; //{maxY, sum}
    int curY = x-1;
    while (curY >= 1){
        int gcd = 1;
        for (int i = curY; i >= 2; --i){
            if (x % i == 0 && curY % i == 0) {
                gcd = i;
                break;
            }
        }

        if (gcd + curY > maxY.second) {
            maxY = {curY, gcd + curY};
        }
        curY--;
    }

    return maxY.first;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        int x;
        cin >> x;
        cout << testCase(x) << '\n';
    }

    return 0;
}