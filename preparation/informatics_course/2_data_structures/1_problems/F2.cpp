#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool checkContainers(vector<stack<int>>& containers, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < containers[i].size(); i++){

        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<stack<int>> containers;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        stack<int> container;
        for (int i = 0; i < k; i++){
            int ki;
            cin >> ki;
            container.push(ki);
        }
        containers.push_back(container);
    }



}