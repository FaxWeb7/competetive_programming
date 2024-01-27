#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long sumOfMinimums(const vector<int>& arr, int n) {
    stack<int> s;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            int j = s.top();
            s.pop();
            result += arr[j] * (1LL * (i - j) * (j - (s.empty() ? -1 : s.top())));
        }
        s.push(i);
    }

    while (!s.empty()) {
        int j = s.top();
        s.pop();
        result += arr[j] * (1LL * (n - j) * (j - (s.empty() ? -1 : s.top())));
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << sumOfMinimums(arr, n) << endl;

    return 0;
}