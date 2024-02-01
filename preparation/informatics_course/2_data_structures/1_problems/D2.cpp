#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10E5;
int ans = 0;

struct Stack{
    int arr[MAXN];
    int top = -1;

    void push(string symbol){
        if (symbol == "+"){
            arr[top-1] = arr[top] + arr[top-1];
            top--;
        }
        else if (symbol == "-") {
            arr[top-1] = arr[top-1] - arr[top];
            top--;
        } 
        else if (symbol == "*"){
            arr[top-1] = arr[top] * arr[top-1];
            top--;
        } 
        else if (symbol != " ") arr[++top] = stoi(symbol);
        ans = arr[top];
    }
};

int main(){
    Stack stack;
    string symbol;
    while (cin >> symbol){
        stack.push(symbol);
    }

    cout << ans;
}