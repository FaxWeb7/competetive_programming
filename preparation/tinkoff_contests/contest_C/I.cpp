#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

pair<ll, int> newMinPancake(vector<ll>& arr, int arrSize){
    int minIndex = 0;
    ll minNum = arr[minIndex];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] < minNum) {
            minIndex = i;
            minNum = arr[i];
        }
    }
    return pair<ll, int>{minNum, minIndex};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);

    vector<ll> stack;
    int stackSize = 0;

    pair<ll, ll> minPancake = {INT_MAX, -1};
    for(int i = 0; i < t; i++){
        ll num1;
        ll num2 = 0;
        scanf("%lld", &num1);
        if (num1 == 1){
            scanf("%lld", &num2);
        }
        vector<ll> vI{num1, num2};

        if (vI[0] == 1){
            stack.push_back(vI[1]);
            stackSize++;
            if (vI[1] < minPancake.first) minPancake = {vI[1], stackSize-1};
        }
        else if (vI[0] == 2) {
            stack.pop_back();
            stackSize--;
            if (stackSize == minPancake.second){
                minPancake = newMinPancake(stack, stackSize);
            }
        }
        else if (vI[0] == 3) {
            printf("%lld\n", minPancake.first);
        }
    }

    return 0;
}