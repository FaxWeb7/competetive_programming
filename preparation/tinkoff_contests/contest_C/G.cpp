#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPairsWithSumK(vector<int>& arr, int k, bool& isFind) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            cout << "Yes\n" << 1 << "\n";
            cout << arr[i] << endl;
            isFind = true;
            return;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                cout << "Yes\n" << 2 << "\n";
                cout << arr[i] << " " << arr[j] << " " << endl;
                isFind = true;
                return;
            }
            for (int l = j + 1; l < n; l++) {
                if (arr[i] + arr[j] + arr[l] == k) {
                    cout << "Yes\n" << 3 << "\n";
                    cout << arr[i] << " " << arr[j] << " " << arr[l] << endl;
                    isFind = true;
                    return;
                }
                for (int a = l + 1; a < n; a++) {
                    if (arr[i] + arr[j] + arr[l] + arr[a] == k) {
                        cout << "Yes\n" << 4 << "\n";
                        cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << endl;
                        isFind = true;
                        return;
                    }
                    for (int q = a + 1; q < n; q++) {
                        if (arr[i] + arr[j] + arr[l] + arr[a] + arr[q] == k) {
                            cout << "Yes\n" << 5 << "\n";
                            cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << " " << arr[q] << endl;
                            isFind = true;
                            return;
                        }
                        for (int w = q + 1; w < n; w++) {
                            if (arr[i] + arr[j] + arr[l] + arr[a] + arr[q] + arr[w] == k) {
                                cout << "Yes\n" << 6 << "\n";
                                cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << " " << arr[q] << " " << arr[w] << endl;
                                isFind = true;
                                return;
                            }
                            for (int e = w + 1; e < n; e++) {
                                if (arr[i] + arr[j] + arr[l] + arr[a] + arr[q] + arr[w] + arr[e] == k) {
                                    cout << "Yes\n" << 7 << "\n";
                                    cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << " " << arr[q] << " " << arr[w] << " " << arr[e] << endl;
                                    isFind = true;
                                    return;
                                }
                                for (int r = e + 1; r < n; r++) {
                                    if (arr[i] + arr[j] + arr[l] + arr[a] + arr[q] + arr[w] + arr[e] + arr[r] == k) {
                                        cout << "Yes\n" << 8 << "\n";
                                        cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << " " << arr[q] << " " << arr[w] << " " << arr[e] << " " << arr[r] << endl;
                                        isFind = true;
                                        return;
                                    }
                                    for (int t = r + 1; t < n; t++) {
                                        if (arr[i] + arr[j] + arr[l] + arr[a] + arr[q] + arr[w] + arr[e] + arr[r] + arr[t] == k) {
                                            cout << "Yes\n" << 9 << "\n";
                                            cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[a] << " " << arr[q] << " " << arr[w] << " " << arr[e] << " " << arr[r] << " " << arr[t] << endl;
                                            isFind = true;
                                            return;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(2*n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        v.push_back(num);
    }
    sort(v.rbegin(), v.rend());

    bool isFind = false;
    findPairsWithSumK(v, k, isFind);
    if (!isFind) cout << "No";
    
    return 0;
}