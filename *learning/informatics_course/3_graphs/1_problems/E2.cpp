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
        for (int j = i+1; j < n; j++){
            if (graph[i][j]){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }

    return 0;
}