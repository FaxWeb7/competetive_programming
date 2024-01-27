#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    private:
        int size;
        vector<int> heap;
        void heapify(int i){
            int minI = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < size && heap[l] < heap[minI]) minI = l;
            if (r < size && heap[r] < heap[minI]) minI = r;

            if (minI != i){
                swap(heap[i], heap[minI]);
                heapify(minI);
            }
        }

    public: 
        MinHeap(){
            size = 0;
        }
        void insert(int value){
            heap.push_back(value);
            size++;
            for (int i = size / 2 - 1; i >= 0; i--) heapify(i);
        }

        int getMin(){
            return heap[0];
        }

        void extractMin(){
            
        }
};

int main(){
    int n, k;
    cin >> n >> k;

    MinHeap heap;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        heap.insert(num);
        if (i >= k-1){
            ans.push_back(heap.getMin());
            heap.extractMin();
        }
    }

    for (int num : ans) cout << num << endl;

    return 0;
}