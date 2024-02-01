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
            return arr[top];
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

int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    cout << stack.pop() << endl;
    cout << stack.pop() << "\n\n";

    Queue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.pop();
    cout << queue.pop() << "\n\n";


    return 0;
}
