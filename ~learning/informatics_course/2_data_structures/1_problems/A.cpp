#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Stack{
    int top = -1;
    int arr[MAX_SIZE];

    void push(int n){
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
}