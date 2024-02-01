#include <iostream>
using namespace std;

struct Stack{
    int top = -1;
    int capacity = 1;
    int *arr = new int[capacity];

    void doubleCapacity() {
        int* new_arr = new int[capacity*=2];
        for (int i = 0; i < capacity / 2; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }


    void push(int n){
        if (top == capacity-1) doubleCapacity();
        arr[++top] = n;
        cout << "ok\n";
    }
    void pop(){
        if (top != -1) cout << arr[top--] << endl;
        else cout << "error\n";
    }
    void back(){
        if (top != -1) cout << arr[top] << endl;
        else cout << "error\n";
    }
    void size(){
        cout << top+1 << endl;
    }
    void clear(){
        top = -1;
        cout << "ok\n";
    }

    // деструктор для освобождения памяти, занимаемой массивом после завершения работы со стеком
    ~Stack() {
        delete[] arr;
    }
};

int main(){
    Stack stack;
    string command;

    do {
        cin >> command;
        if (command == "push"){
            int n;
            cin >> n;
            stack.push(n);
        }
        else if (command == "pop") stack.pop();
        else if (command == "back") stack.back();
        else if (command == "size") stack.size();
        else if (command == "clear") stack.clear(); 
    } while (command != "exit");

    cout << "bye";
    return 0;
}