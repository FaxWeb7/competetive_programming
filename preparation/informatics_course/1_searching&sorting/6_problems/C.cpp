#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<char, int> getStringData(string word){
    unordered_map<char, int> res{};
    for (char symbol : word){
        if (res.find(symbol) == res.end()){
            res[symbol] = 0;
        }
        res[symbol]++;
    }

    return res;
}

int main(){
    string w1, w2;
    getline(cin, w1);
    getline(cin, w2);
    
    string ans = "YES";
    if (w1.size() == w2.size()){
        unordered_map<char, int> w1_data = getStringData(w1);
        unordered_map<char, int> w2_data = getStringData(w2);
        for (pair<char, int> key : w1_data){
            if (w2_data.find(key.first) == w2_data.end() || w2_data[key.first] != key.second){
                ans = "NO";
                break;
            } 
        }
    } else ans = "NO";

    cout << ans;

    return 0;
}