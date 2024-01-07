#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6};

    int x = 5;
    int answer = -1;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == x) {
            answer = i+1;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}