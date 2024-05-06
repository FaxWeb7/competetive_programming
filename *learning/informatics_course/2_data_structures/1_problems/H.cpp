#include <iostream>
using namespace std;

struct Deque{
    int capacity = 100;
    int *arr = new int[capacity];
    int head = 0;
    int tail = -1;

    void pushFront(int num){
        arr[--head % capacity] = num;
        cout << "ok\n";
    }
    void pushBack(int num){
        arr[++tail % capacity] = num;
        cout << "ok\n";
    }
    void popFront(){
        if (tail >= head){
            cout << arr[head++ % capacity] << endl;
        } else cout << "error\n";
    }
    void popBack(){
        if (tail >= head){
            cout << arr[tail-- % capacity] << endl;
        } else cout << "error\n";
    }
    void front(){
        if (tail >= head){
            cout << arr[head % capacity] << endl;
        } else cout << "error\n";
    }
    void back(){
        if (tail >= head){
            cout << arr[tail % capacity] << endl;
        } else cout << "error\n";
    }
    void size(){
        cout << ((tail%capacity) - (head%capacity) + 1) << endl;
    }
    void clear(){
        head = 0;
        tail = -1;
        cout << "ok\n";
    }
};

int main(){
    Deque deque;
    string command;
    do{
        cin >> command;
        if (command == "push_front"){
            int num;
            cin >> num;
            deque.pushFront(num);
        } else if (command == "push_back"){
            int num;
            cin >> num;
            deque.pushBack(num);
        } 
        else if (command == "pop_front") deque.popFront();
        else if (command == "pop_back") deque.popBack();
        else if (command == "front") deque.front();
        else if (command == "back") deque.back();
        else if (command == "size") deque.size();
        else if (command == "clear") deque.clear();

    } while (command != "exit");
    cout << "bye";

    return 0;
}