#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double a;
    double n;
    cout << numeric_limits<long double>::max();
    cin >> a >> n;

    double left = 0.0;
    double right = a;
    double const EPS = 0.00000001;
    while (right-left >= EPS){
        double mid = (left + right) / 2.0;
        if (pow(mid, n) > a) right = mid;
        else left = mid;
    }
    cout << fixed << setprecision(10) << (right+left)/2;
    return 0;
}