#include <iostream>
#include <vector>
#include <string> //stod (from str to doubl)
#include <iomanip> //setfill, setw
#include <cmath> //ceil

using namespace std;
using ll = long long int;


int main(){
    int vMax, d, N;
    cin >> vMax >> d;
    cin >> N;

    vector<double> vX;
    vector<double> vT;
    vX.reserve(N);
    vT.reserve(N);

    for (int i = 0; i < N; i++){
        double xi;
        string time;
        cin >> xi >> time;

        int index = time.find(':');
        double timeMinutes = (stod(time.substr(0, index))*60) + stod(time.substr(index+1));
        vX.push_back(xi);
        vT.push_back(timeMinutes);
    }
    
    double nowS = 0;
    double nowT = 0;
    for (int i = 0; i < N; i++){
        double localTime = (abs(vX[i] - nowS) / vMax);
        if ((localTime+nowT) < vT[i]) localTime += (vT[i]-(localTime+nowT));
        nowT += localTime+d;
        nowS = vX[i];
    }
    int ans = ceil(nowT + (nowS/vMax));
    int ansHours = ans / 60;
    int ansMinutes = ans % 60;
    cout << setfill('0') << setw(2) << to_string(ansHours) << ":";
    cout << setfill('0') << setw(2) <<  to_string(ansMinutes) << endl;

    return 0;
}