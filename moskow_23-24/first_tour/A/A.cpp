#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int daysInMonth(int month, int year) {
    vector<int> daysInEachMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return 29;
    }
    return daysInEachMonth[month - 1];
}

int countDays(string date1, string date2) {
    int day1 = stoi(date1.substr(0, 2));
    int month1 = stoi(date1.substr(3, 2));
    int year1 = stoi(date1.substr(6, 4));
    int day2 = stoi(date2.substr(0, 2));
    int month2 = stoi(date2.substr(3, 2));
    int year2 = stoi(date2.substr(6, 4));
    
    int totalDays = 0;
    while (day1 != day2 || month1 != month2 || year1 != year2) {
        totalDays++;
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }
    
    return totalDays;
}

int main(){
    vector<int> res;

    string line, date1, date2;
    ifstream in("a2.txt");
    if (in.is_open()){
        while (getline(in, line)){
            date1 = line.substr(0, 10);
            date2 = line.substr(11, 20);
            res.push_back(countDays(date1, date2));
        }
    }
    in.close();

    ofstream out;
    out.open("a2ans.txt");
    if (out.is_open()){
        for (int num : res) out << num << endl;
    }
    out.close();
    return 0;
}