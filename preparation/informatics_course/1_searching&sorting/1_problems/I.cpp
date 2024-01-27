#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cin.ignore();
    
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++){
        vector<int> row;

        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) row.push_back(num);

        matrix.push_back(row);
    }
    
    vector<int> minNumsRow;
    vector<int> maxNumsCol;
    for (int i = 0; i < n; i++){
        int minV = INT_MAX;
        for (int j = 0; j < m; j++){
            if (matrix[i][j] < minV) minV = matrix[i][j];
        }
        minNumsRow.push_back(minV);
    }
    for (int i = 0; i < m; i++){
        int maxV = INT_MIN;
        for (int j = 0; j < n; j++){
            if (matrix[j][i] > maxV) maxV = matrix[j][i];
        }
        maxNumsCol.push_back(maxV);
    }

    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == minNumsRow[i] && matrix[i][j] == maxNumsCol[j]) counter++;
        }
    }

    cout << counter;

    return 0;
}