#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dividersSum(int n){
    int res = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            res += i;
            if (n / i != i) {
                res += n / i;
            }
        }
    }

    return res;
}

int main(){
    int k;
    cin >> k;

    vector<pair<int, int>> res;
    for (int i = 1; i < k; ++i){
        int j = dividersSum(i);
        if (j > i && j < k && dividersSum(j) == i){
            res.push_back({i, j});
        }
    }

    for (auto &[n, m] : res){
        cout << n << ' ' << m << ' ';
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// // Функция для нахождения всех делителей числа n и вычисления их суммы
// int sumOfDivisors(int n) {
//     int sum = 1; // Учитываем делитель 1
//     for (int i = 2; i <= sqrt(n); ++i) {
//         if (n % i == 0) {
//             sum += i;
//             if (n / i != i) { // Если i не является квадратным корнем, учитываем делитель n/i
//                 sum += n / i;
//             }
//         }
//     }
//     return sum;
// }

// int main() {
//     int k;
//     cin >> k;
    
//     vector<pair<int, int>> friendlyPairs;

//     for (int n = 2; n <= k; ++n) {
//         int m = sumOfDivisors(n);
//         if (m > n && m <= k && sumOfDivisors(m) == n) {
//             friendlyPairs.push_back(make_pair(n, m));
//         }
//     }

//     for (auto pair : friendlyPairs) {
//         cout << pair.first << ' ' << pair.second << ' ';
//     }

//     return 0;
// }
