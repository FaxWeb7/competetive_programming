#include <iostream>
using namespace std;

int countGuesses(int n){
    int left = 1;
    int right = n;
    int guesses = 0;
    while (left != right){
        int mid = (left + right) / 2;
        if (mid == 1) {
            guesses++;
            break;
        }
        else if (mid < 1){
            left = mid + 1;
            guesses++;
        }
        else {
            right = mid;
            guesses++;
        }
    }
    return guesses;
}

int main(){
    int n;
    cin >> n;

    cout << countGuesses(n);

    return 0;
}