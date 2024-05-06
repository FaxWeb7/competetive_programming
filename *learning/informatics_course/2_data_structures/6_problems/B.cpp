#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

struct Friend {
    ll money;
    ll power;
    Friend(ll money, ll power) {
        this->money = money;
        this->power = power;
    }
};

int main(){
    int n;
    ll d;
    cin >> n >> d;
    vector<Friend> friends(n, {0,0});
    for (int i = 0; i < n; i++){
        ll money, power;
        cin >> money >> power;
        friends[i] = {money, power};
    }

    ll maxPower = 0;
    ll curPower = 0;
    int l = 0;
    for (int r = 0; r < n; r++){
        curPower += friends[l].power;
        while (r < n && friends[l].money + d > friends[r].money){
            curPower += friends[r].power;
            r++;
        }

        maxPower = max(maxPower, curPower);
        curPower -= friends[l].power;
    }

    cout << maxPower;

    return 0;
}
