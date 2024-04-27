#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 4;
    vector<int> arr{8,4,12,6};

    //сортировка пузырьком
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // сортировка выбором
    for (int i = 0; i < n-1; i++){
        int minI = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[minI]) {
                minI = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = temp;
    }

    //сортировка вставками
    for (int i=1; i<n; i++){
        for(int j=i; j>0 && arr[j-1]>arr[j]; j--){
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
        }
    }


    //сортировка Шелла
    for (int d = n/2; d > 0; d /= 2){
        for (int i = d; i < n; i++){
            for (int j = i; j >= d; j -= d){
                if (arr[i] < arr[j-d]){
                    int temp = arr[i];
                    arr[i] = arr[j-d];
                    arr[j-d] = temp;
                }
            }
        }
    }
    for (auto i : arr) cout << i << " ";
    return 0;
}