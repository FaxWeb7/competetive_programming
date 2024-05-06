#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    vector<pair<int, string>> nine, ten, eleven;

    int grade;
    string lastName;
    while (cin >> grade >> lastName) {
        if (grade == 9) nine.push_back({grade, lastName});
        if (grade == 10) ten.push_back({grade, lastName});
        if (grade == 11) eleven.push_back({grade, lastName});
    }

    for (int i = 0; i < nine.size(); i++) cout << nine[i].first << " " << nine[i].second << endl;
    for (int i = 0; i < ten.size(); i++) cout << ten[i].first << " " << ten[i].second << endl;
    for (int i = 0; i < eleven.size(); i++) cout << eleven[i].first << " " << eleven[i].second << endl;

    return 0;
}