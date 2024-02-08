#include <iostream>
using namespace std;

const int capacity = 100;

struct Queue{
    int arr[capacity];
    int head = -1;
    int tail = -1;

    void push(int num){
        if (head == -1) head = 0;
        arr[++tail % capacity] = num;
    }

    int pop(){
        return arr[head++ % capacity];
    }

    int getSize(){
        if (tail == -1) return 0;
        else return tail-head+1;
    }
};

int main() {
    Queue deck1;
    Queue deck2;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        deck1.push(num);
    }
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        deck2.push(num);
    }

    int moves = 0;

    while (deck1.getSize() != 0 && deck2.getSize() != 0){
        int head1 = deck1.pop();
        int head2 = deck2.pop();

        if (head1 == 0 && head2 == 9){
            deck1.push(head1);
            deck1.push(head2);
        }
        else if (head2 == 0 && head1 == 9){
            deck2.push(head1);
            deck2.push(head2);
        }
        else if (head1 > head2){
            deck1.push(head1);
            deck1.push(head2);
        } else {
            deck2.push(head1);
            deck2.push(head2);
        }
        moves++;
    }

    if (moves >= 10E6) cout << "botva";
    else if (deck1.getSize() == 0) cout << "second" << " " << moves;
    else  cout << "first" << " " << moves;
    
    return 0;
}