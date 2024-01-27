#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n-1; i >= 0; i--){
        int maxI = i;
        for (int j = i-1; j >= 0; j--){
            if (arr[maxI] < arr[j]){
                maxI = j;
            }
        }
        int temp = arr[maxI];
        arr[maxI] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}