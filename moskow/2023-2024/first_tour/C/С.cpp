#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> getMaxYield(vector<int>& A, vector<int>& B, int N) {
    int maxSum = 0;
    vector<int> maxCultures;

    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> selectedCultures;
        int sumA = 0;
        int sumB = 0;

        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) {
                selectedCultures.push_back(j);
                sumA += A[j];
                sumB += B[j];
            }
        }

        if (sumA == sumB && sumA + sumB > maxSum) {
            maxSum = sumA + sumB;
            maxCultures = selectedCultures;
        }
    }

    cout << maxCultures.size() << "\n";
    for (int culture : maxCultures) {
        cout << culture + 1 << " ";
    }
    cout << "\n";
    return {maxCultures.size(), maxCultures};
}

int main() {
    ifstream in("c2.txt");
    vector<pair<int, vector<int>>> ans;
    if (in.is_open()){
        int t;
        in >> t;
        for (int i = 0; i < t; i++) {
            int N;
            in >> N;
            vector<int> A(N);
            vector<int> B(N);
            for (int j = 0; j < N; j++) {
                in >> A[j];
            }
            for (int j = 0; j < N; j++) {
                in >> B[j];
            }

            pair<int, vector<int>> res = getMaxYield(A, B, N);
            ans.push_back(res);
        }
    }
    in.close();

    ofstream out;
    out.open("c2ans.txt");
    if (out.is_open()){
        for (auto i : ans){
            out << i.first << endl;
            for (auto j : i.second){
                out << j+1 << " ";
            }
            out << endl;
        }
    }
    out.close();
}