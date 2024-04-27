#include <iostream>
#include <cmath>
using namespace std;

int calculateFlightTime(int departureHour, int departureMinute, int arrivalHour, int arrivalMinute) {
    int totalDepartureMinutes = departureHour * 60 + departureMinute;
    int totalArrivalMinutes = arrivalHour * 60 + arrivalMinute;
    
    if (totalDepartureMinutes > totalArrivalMinutes) {
        totalArrivalMinutes += 24 * 60;
    }

    return totalArrivalMinutes - totalDepartureMinutes;
}

int main() {
    int s1h, s1m, f1h, f1m, s2h, s2m, f2h, f2m;
    cin >> s1h >> s1m >> f1h >> f1m >> s2h >> s2m >> f2h >> f2m;

    int forwardFlightTime = calculateFlightTime(s1h, s1m, f1h, f1m);
    int backwardFlightTime = calculateFlightTime(s2h, s2m, f2h, f2m);

    cout << ceil(((double)(forwardFlightTime / 60) + (double)(backwardFlightTime / 60)) / 2.0) << " " << forwardFlightTime % 60 << endl;
    cout << (forwardFlightTime+backwardFlightTime)/2 / 60 << " " << backwardFlightTime % 60 << endl;
    
    return 0;
}
