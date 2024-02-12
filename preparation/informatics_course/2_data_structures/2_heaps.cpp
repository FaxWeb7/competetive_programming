#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
    int arr[100];
    int size = 0;

    int getMin(){
        return arr[0];
    }

    void add(int num){
        int current = size;
        arr[size++] = num;
        while (current > 0 && arr[current] < arr[(current-1) / 2]){
            swap(arr[current], arr[(current-1) / 2]);
            current = (current-1) / 2;
        }
    }

    void delMin(){
        int current = 0;
        arr[0] = arr[--size];
        while (current*2+1 < size){
            int minP = (arr[2*current+1] < arr[2*current+2] ? 2*current+1 : 2*current+2);
            if (arr[current] > arr[minP]){
                swap(arr[current], arr[minP]);
                current = minP;
            } else break;
        }
    }
};

int main(){
    MinHeap heap;
    heap.add(6);
    heap.add(4);
    heap.add(5);
    heap.add(8);
    heap.add(12);
    heap.add(25);
    heap.add(11);
    heap.add(2);
    heap.add(20);

    for (int i = 0; i < heap.size; i++) cout << heap.arr[i] << " ";

    return 0;
}