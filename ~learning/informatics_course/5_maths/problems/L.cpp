#include <iostream>
#include <numeric>

using namespace std;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int xDiff = abs(x1 - x2);
    int yDiff = abs(y1 - y2);

    cout << gcd(xDiff, yDiff) + 1;

    return 0;
}