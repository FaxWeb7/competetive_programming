#include <iostream>
#include <vector>
using namespace std;

vector<int> countSort(vector<int>& arr, int n) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range);
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    vector<int> sortedArr;
    for (int i = 0; i < range; i++) {
        for (int j = i; j < i+count[i]; j++){
            sortedArr.push_back(i+min);
        }
    }
    return sortedArr;
}

int main(){
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> v1(n), v2(n), reqs(m);
    for (int i = 0; i < n; i++) cin >> v1[i] >> v2[i];
    for (int i = 0; i < m; i++) cin >> reqs[i];

    v1 = countSort(v1, n);
    v2 = countSort(v2, n);

    for (int req : reqs){
        int ans = 0;
        for (int i = 0; i < n && v1[i] <= req; i++){
            if (v1[i] <= req && v2[i] >= req)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}