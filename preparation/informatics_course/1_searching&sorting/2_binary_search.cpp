#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int binarySearch(vector<int> &arr, int x){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (arr[mid] < x) left = mid + 1;
        else right = mid;
    }
    return (arr[right] == x ? right : -1);
}

double epsBinarySearch(double x){
    double eps = 0.000001;
    double left = 1;
    double right = x;
    while (abs(left - right) > eps){
        double mid = (left + right) / 2;
        if (mid*mid*mid == x) return mid;
        else if (mid*mid*mid < x) left = mid;
        else right = mid;
    }
    return right;
}

int answerBinarySearch(int N, int x, int y){
    int left = 0;
    int right = N * (x > y ? x : y);
    int preAns;
    while (left != right){
        int mid = (left + right) / 2;
        preAns = (mid/x + mid/y);
        if (preAns < N-1) left = mid + 1;
        else right = mid;
    }
    return preAns + (x < y ? x : y);
}

int main(){
    // EX.1
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << binarySearch(arr, 10) << endl;

    // EX.2
    // double x = 12.324;
    // cout << fixed << setprecision(6) << epsBinarySearch(x) << endl;

    // EX.3
    int N, x, y;
    cin >> N >> x >> y;
    cout << answerBinarySearch(N, x, y) << endl;

    return 0;
}