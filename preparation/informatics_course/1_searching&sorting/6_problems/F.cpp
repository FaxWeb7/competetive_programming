#include <iostream>
#include <unordered_map>
using namespace std;

struct Key{
    int limit;
    int used;
};

int main(){
    int n, k;
    cin >> n;
    unordered_map<int, Key> keys;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        keys[i] = {c, 0};
    }

    cin >> k;
    for (int i = 0; i < k; i++){
        int p;
        cin >> p;
        keys[p-1].used++;
    }

    for (int i = 0; i < n; i++){
        cout << (keys[i].used > keys[i].limit ? "yes" : "no") << endl;
    }

    return 0;
}