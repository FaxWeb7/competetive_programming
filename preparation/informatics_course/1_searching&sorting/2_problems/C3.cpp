#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    long double c;
    cin >> c;

    long double left = 0.0000000;
    long double right = sqrt(c);
    long double ans;
    while (right-left >= 10E-13){
        long double mid = (left + right) / 2;
        if (fabs(((mid*mid) + sqrt(mid))) < c) {
            ans = mid;
            left = mid;
        }
        else right = mid;
    }

    cout << fixed << setprecision(9) << ans;

    return 0;
}