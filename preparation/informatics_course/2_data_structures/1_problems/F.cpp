#include <iostream>
using namespace std;

struct Queue{
    int tail = -1;
    int head = -1;
    int capacity = 10000;
    int *arr = new int[capacity];

    void doubleCapacity(){
        int *newArr = new int[capacity*=2];
        for (int i = 0; i < capacity/2; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void push(int num){
        if (head == -1) head = 0;
        if (tail == capacity-1) doubleCapacity();
        arr[(++tail)%capacity] = num;
        cout << "ok\n";
    }
    void pop(){
        if (head <= tail && head != -1){
            cout << arr[(head++)%capacity] << endl;
        } else cout << "error\n";
    }
    void front(){
        if (head <= tail && head != -1){
            cout << arr[head%capacity] << endl;
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

    ~Queue(){
        delete[] arr;
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