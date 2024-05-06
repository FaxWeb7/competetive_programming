#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char, int> count;
    for (int i = 0; i < n; i++) {
        char symbol;
        cin >> symbol;
        if (count.find(symbol) == count.end()){
            count[symbol] = 0;
        }
        count[symbol]++;
    }

    char maxOddSymbol = '1';
    int maxOddCount = 0;
    for (auto symbol : count){
        if (symbol.second % 2 != 0 && (symbol.second > maxOddCount)) {
            maxOddSymbol = symbol.first;
            maxOddCount = symbol.second;
        }
    }

    string ans = "";
    int ansLen = 0;
    for (auto symbol : count){
        if (symbol.second % 2 == 0){
            for (int i = 0; i < symbol.second/2; i++) {
                ans += symbol.first;
                ansLen++;
            }
        }
    }

    for (int i = 0; i < maxOddCount; i++) {
        ans += maxOddSymbol;
    }
    for (int i = ansLen-1; i >= 0; i--){
        ans += ans[i];
    }

    cout << ans;

    return 0;
}