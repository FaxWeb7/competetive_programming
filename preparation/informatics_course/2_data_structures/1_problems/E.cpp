#include <iostream>
using namespace std;

const int MAXN = 10000;

struct Queue{
    int tail = -1;
    int head = -1;
    int arr[MAXN];

    void push(int num){
        if (head == -1) head = 0;
        arr[(++tail)%MAXN] = num;
        cout << "ok\n";
    }
    void pop(){
        if (head <= tail && head != -1){
            cout << arr[(head++)%MAXN] << endl;
        } else cout << "error\n";
    }
    void front(){
        if (head <= tail && head != -1){
            cout << arr[head%MAXN] << endl;
        } else cout << "error\n";
    }
    void getSize(){
        if (tail == -1) cout << 0 << endl;
        else cout << tail-head+1 << endl;
    }
    void clear(){
        tail = -1;
        head = -1;
        cout << "ok\n";
    }
};

int main() {
    Queue queue;
    string command;
    do {
        cin >> command;
        if (command == "push"){
            int num;
            cin >> num;
            queue.push(num);
        }
        else if (command == "pop") queue.pop();
        else if (command == "front") queue.front();
        else if (command == "size") queue.getSize();
        else if (command == "clear") queue.clear();

    } while (command != "exit");
    cout << "bye";

    return 0;
}