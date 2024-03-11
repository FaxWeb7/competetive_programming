#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> sources;
    vector<int> drains;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        bool isSource = true;
        bool isDrain = true;
        for (int j = 0; j < n; j++){
            if (graph[j][i]) isSource = false;
            if (graph[i][j]) isDrain = false;
        }
        if (isSource) sources.push_back(i+1);
        if (isDrain) drains.push_back(i+1);
    }

    cout << sources.size() << endl;
    for (int i = 0; i < sources.size(); i++) cout << sources[i] << endl;
    cout << drains.size() << endl;
    for (int i = 0; i < drains.size(); i++) cout << drains[i] << endl;

    return 0;
}