#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && arr[j-1] > arr[j]; j--){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }

    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}