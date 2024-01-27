#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

bool canBalloonsBeBlown(int M, int N, const vector<ll>& T, const vector<ll>& Z, const vector<ll>& Y, ll time) {
    ll balloonsBlown = 0;
    for (int i = 0; i < N; i++) {
        ll guess = time;
        long double cycles = static_cast<long double>(guess) / (T[i] * Z[i] + Y[i]);
        ll localBalloonsBlown = 0;
        if (cycles >= 1.0){
            long double remainder = cycles - floor(cycles);
            long double oneBalloonTime = static_cast<long double>(T[i]) / (T[i]*Z[i] + Y[i]);
            if (remainder == 0.0){
                balloonsBlown += floor(cycles)*Z[i];
            }else {
                ll c = 0;
                while (floor((remainder / oneBalloonTime)+0.00001)-c > Z[i]){
                    c++;
                }
                
                ll remBalloons = (floor((remainder / oneBalloonTime)+0.00001))-c;
                balloonsBlown += remBalloons + floor(cycles)*Z[i];
            }
        } else{
            long double remainder = cycles - floor(cycles);
            long double oneBalloonTime = static_cast<long double>(T[i]) / (T[i]*Z[i] + Y[i]);
            ll c = 0;
                while (floor((remainder / oneBalloonTime)+0.00001)-c > Z[i]){
                    c++;
                }
                
            ll remBalloons = (floor((remainder / oneBalloonTime)+0.00001))-c;
            balloonsBlown += remBalloons;

        }
    }
    return (balloonsBlown >= M);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int M, N;
    scanf("%d%d", &M, &N);
    vector<ll> T(N), Z(N), Y(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld%lld", &T[i], &Z[i], &Y[i]);
    }

    ll left = 0;
    ll right = 1e9+1;
    ll ans = 0;
    while (left < right){
        ll mid = (left + right) / 2;
        if (canBalloonsBeBlown(M, N, T, Z, Y, mid)) {
            ans = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%lld", ans);

    return 0;
}