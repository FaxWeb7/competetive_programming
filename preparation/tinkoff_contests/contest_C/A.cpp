#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    int m, n;
    cin >> m >> n;
    vector<ll> vT(n), vZ(n), vY(n);
    for (int i = 0; i < n; i++){
        cin >> vT[i] >> vZ[i] >> vY[i];
    }

    int nowBaloons = 0;
    ll nowTime = 0;
    while (nowBaloons < m){
        for (int i = 0; i < n; i++){

        }
        nowTime++;
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;
// using ll = long long;

// bool canBalloonsBeBlown(int M, int N, const vector<ll>& T, const vector<ll>& Z, const vector<ll>& Y, ll time) {
//     ll balloonsBlown = 0;
//     for (int i = 0; i < N; i++) {
//         ll t = 0;
//         while (t + T[i] <= time && balloonsBlown < M) {
//             balloonsBlown++;
//             t += T[i];
//             if (balloonsBlown % Z[i] == 0 && balloonsBlown < M) {
//                 t += Y[i];
//             }
//         }
//     }
//     return (balloonsBlown >= M);
// }

// int main() {
//     int M, N;
//     cin >> M >> N;
//     vector<ll> T(N), Z(N), Y(N);
//     for (int i = 0; i < N; i++) {
//         cin >> T[i] >> Z[i] >> Y[i];
//     }

//     ll left = 0, right = 1e18;
//     ll ans = 0;
//     while (left <= right) {
//         ll mid = (left + right) / 2;
//         if (canBalloonsBeBlown(M, N, T, Z, Y, mid)) {
//             ans = mid;
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }
