#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> grades;
    int grade;
    while (ss >> grade) grades.push_back(grade);

    int maxGrade = INT_MIN;
    int minGrade = INT_MAX;
    for (int i = 0; i < n; i++){
        if (grades[i] > maxGrade) maxGrade = grades[i];
        if (grades[i] < minGrade) minGrade = grades[i];
    }
    for (int i = 0; i < n; i++){
        int nowGrade = grades[i];
        if (nowGrade == maxGrade){
            nowGrade = minGrade;
        }
        cout << nowGrade << ' ';
    }
}