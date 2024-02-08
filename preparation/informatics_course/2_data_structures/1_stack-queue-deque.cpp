#include <iostream>
using namespace std;

const int MAXN = 100;

struct Stack {
    int top = -1;
    int arr[MAXN];

    void push(int val) {
        if (top != MAXN - 1){
            arr[++top] = val;
        } else cout << "stack overflow\n";
    }
    int pop(){
        if (top != -1){
            return arr[top--];
        } return -1;
    }
};

struct Queue{
    int tail = -1;
    int head = -1;
    int arr[MAXN];

    void push(int num){
        if (head == -1) head = 0;
        arr[(++tail)%MAXN] = num;
    }
    int pop(){
        if (head <= tail && head != -1){
            return arr[(head++)%MAXN];
        } return -1;
    }
};

struct Deque{
    int capacity = 100;
    int* arr = new int[capacity];
    int front = 0;
    int back = -1;

    bool isEmpty() { return back < front; }
    bool isFull() { return back - front + 1 >= capacity; }

    void pushFront(int n) {
        if (!isFull()) {
            arr[--front % capacity] = n;
        } else cout << "deque is full" << endl;
    }

    void pushBack(int n) {
        if (!isFull()) {
            arr[++back % capacity] = n;
        } else cout << "deque is full\n";
    }

    int popFront() {
        if (!isEmpty()) {
            return arr[front++ % capacity];
        } return -1;
    }

    int popBack() {
        if (!isEmpty()) {
            return arr[back-- % capacity];
        } return -1;
    }

    int getFront() {
        if (!isEmpty()) {
            return arr[front % capacity];
        } return -1;
    }

    int getBack() {
        if (!isEmpty()) {
            return arr[back % capacity];
        } return -1;
    }
};


int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    cout << stack.pop() << endl;
    cout << stack.pop() << "\n\n";

    Queue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.pop() << endl;
    cout << queue.pop() << "\n\n";

    Deque deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushFront(3);
    deque.pushFront(4);
    cout << deque.popFront() << endl;
    cout << deque.popBack() << "\n\n";


    return 0;
}
