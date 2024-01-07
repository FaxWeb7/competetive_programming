// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// using ll = long long;

// int main(){
//     int n, q;
//     cin >> n >> q;
//     vector<ll> vA(n), vK(q);
//     for (int i = 0; i < n; i++){
//         cin >> vA[i];
//     }
//     ll maxK = INT_MIN;
//     for (int i = 0; i < q; i++){
//         cin >> vK[i];
//         if (vK[i] > maxK) maxK = vK[i];
//     }

//     vector<ll> vA2;
//     int vA2Size = 0;

//     ll guess = 0;
//     ll i = 0;
//     while (vA2Size <= maxK){
//         if (i >= n) {
//             vA2.push_back(vA[n-1]+(i-(n-1)));
//             vA2Size++;
//         }
//         else if (vA[i] != guess){
//             ll diff = vA[i] - guess;
//             for (ll j = diff; j > 0; j--){
//                 vA2.push_back(vA[i]-j);
//             }
//             vA2Size += diff;
//         }
//         guess = vA[i]+1;
//         i++;
//     }
//     for (int i = 0; i < q; i++){
//         cout << vA2[vK[i]-1] << " ";
//     }

//     return 0;
// }






#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), k(q);
    ll maxA;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == n-1) maxA = a[i];
    }
    for (int i = 0; i < q; i++) cin >> k[i];

    vector<ll> kex;
    int kexSize = 0;
    ll maxKex = -1;
    ll guess = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != guess){
            // cout << a[i] << " " << a[i+1] << " " << guess << endl;
            for (ll j = 0; j < a[i]-guess; j++){
                kex.push_back(guess+j);
                maxKex = guess+j;
                kexSize++;
            }
        }
        guess = a[i]+1;
    }

    ll maxEl = (maxA > maxKex ? maxA : maxKex);
    // for (ll num : kex){
    //     cout << num << " ";
    // }
    for (ll i = 0; i < q; i++){
        if (k[i] > kexSize){
            cout << maxEl+k[i]-kexSize << " ";
        } else {
            cout << kex[k[i]-1] << " ";
        }
    }

    return 0;
}