#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> deque1, deque2;

    int ans[n];
    int cnt = 0;
    for (int i = 0; i < n; i++){
        char command;
        cin >> command;
        if (command == '+'){
            int id;
            cin >> id;
            deque2.push_back(id);
        } else if (command == '*'){
            int id;
            cin >> id;
            deque2.push_front(id);
        } else {
            cout << deque1.front() << endl;
            deque1.pop_front();
        }
        
        if (deque1.size() < deque2.size()){
            deque1.push_back(deque2.front());
            deque2.pop_front();
        }
    }

    for (int i = 0; i < cnt; i++) cout << ans[i] << endl;

    return 0;
}