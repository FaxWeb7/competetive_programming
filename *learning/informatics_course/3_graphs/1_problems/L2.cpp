#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            if (a){
                graph[i].push_back(a);
            }
        }
        cout << graph[i].size() << endl;
    }

    return 0;
}