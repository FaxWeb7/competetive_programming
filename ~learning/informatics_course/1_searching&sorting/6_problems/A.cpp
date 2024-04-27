#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> count(range);
    for (int i = 0; i < n; i++){
        count[arr[i]-min]++;
    }
    for (int i = 0; i < range; i++){
        for (int j = i; j < count[i]+i; j++){
            cout << i+min << " ";
        }
    }

    return 0;
}