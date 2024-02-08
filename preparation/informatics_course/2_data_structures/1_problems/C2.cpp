#include <iostream>
using namespace std;

const int capacity = 10e5;

struct Stack{
    char arr[capacity];
    int top = -1;
    bool ans = true;

    void push(char symbol){
        if (symbol == ')' && arr[top] == '(') top--;
        else if (symbol == ']' && arr[top] == '[') top--;
        else if (symbol == '}' && arr[top] == '{') top--;
        else if (symbol == '}' || symbol == ']' || symbol == '}') ans = false;
        else arr[++top] = symbol;
    }
    char isEmpty(){
        return (top == -1);
    }

};

int main(){
    Stack stack;
    string seq;
    cin >> seq;

    for (int i = 0; i < seq.size(); i++){
        stack.push(seq[i]);
    }

    if (!stack.isEmpty()) cout << "no";
    else cout << (stack.ans ? "yes" : "no");

    return 0;
}