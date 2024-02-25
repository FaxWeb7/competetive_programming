#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    char type;
    string word;
    unordered_set<string> set;

    while (true){
        cin >> type;
        if (type == '#') break;

        if (type == '+'){
            cin >> word;
            set.insert(word);
        } 
        else if (type == '-'){
            cin >> word;
            if (set.find(word) != set.end()){
                set.erase(word);
            }
        }
        else {
            cin >> word;
            if (set.find(word) != set.end()){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}