#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> split(const string& str) {
    vector<int> tokens;
    istringstream iss(str);
    string token;
    
    while (getline(iss, token, ' ')) {
        tokens.push_back(stoi(token));
    }
    
    return tokens;
}


int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line);

        vector<int> splittedLine = split(line);
        for (int num : splittedLine){
            graph[i].push_back(num);
        }
    }

    vector<vector<int>> resGraph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < static_cast<int>(graph[i].size()); j++){
            int curItem = graph[i][j];
            resGraph[curItem-1].push_back(i+1);
        }
    }

    cout << n << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < static_cast<int>(resGraph[i].size()); j++){
            cout << resGraph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}