#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        vector<int> heap;
        void heapify(int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < heap.size() && heap[left] > heap[largest]) largest = left;
            if (right < heap.size() && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                heapify(largest);
            }
        }

    public:
        void insert(int key) {
            heap.push_back(key);
            for (int i = heap.size() / 2 - 1; i >= 0; i--) 
                heapify(i);
        }

        int extractMax() {
            int max = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);
            return max;
        }
};


int main(){
    int n;
    cin >> n;
    MaxHeap heap;

    vector<int> arr;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        int command, num;
        cin >> command;
        if (command == 0) {
            cin >> num;
            heap.insert(num);
        } else {
            ans.push_back(heap.extractMax());
        }
    }

    for (int num : ans) cout << num << endl;

    return 0;
}