#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        int in = 0, out = 0;
        for (int j = 0; j < n; j++){
            if (graph[j][i]) in++;
            if (graph[i][j]) out++;
        }
        cout << in << endl << out << endl;
    }

    return 0;
}