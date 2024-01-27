#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

mt19937 gen(42);
int *fsPt[1001], *fdpPt[1001];
unsigned short *lcoPt[1001];
string unfold(int L, int R, string input, string num1);

int main() {
    string input;
    cin >> input;
    int n = input.size();

    for (int i = 0; i < 1001; ++i) {
        fsPt[i] = (i < n ? new int[n] : nullptr);
        fdpPt[i] = (i < n ? new int[n] : nullptr);
        lcoPt[i] = (i <= n ? new unsigned short[n + 1] : nullptr);
        if (lcoPt[i]) {
            for (int j = 0; j <= n; ++j) {
                lcoPt[i][j] = 0;
            }
        }
        if (fsPt[i]) {
            for (int j = 0; j < n; ++j) {
                fsPt[i][j] = 0x1FFFFFFF;
                fdpPt[i][j] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= i; --j) {
            if (input[i] == input[j]) lcoPt[i][j] = 1 + lcoPt[i + 1][j + 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int lm = 0; lm + i <= n; ++lm) {
            int rm = lm + i - 1;
            fsPt[lm][rm] = i;
            for (int mid = lm; mid < rm; ++mid) {
                if (fsPt[lm][rm] > fsPt[lm][mid] + fsPt[mid + 1][rm]) {
                    fsPt[lm][rm] = fsPt[lm][mid] + fsPt[mid + 1][rm];
                    fdpPt[lm][rm] = mid - lm + 1;
                }
            }
            for (int pr = 1; pr < i; ++pr) {
                int lpr = i / pr;
                int len_cur = (lpr < 10 ? 1 : lpr < 100 ? 2 : lpr < 1000 ? 3 : 4);
                if (0 == i % pr && (lcoPt[lm][lm + pr] >= i - pr)) {
                    if (fsPt[lm][rm] > 2 + len_cur + fsPt[lm][lm + pr - 1]) {
                        fsPt[lm][rm] = 2 + len_cur + fsPt[lm][lm + pr - 1];
                        fdpPt[lm][rm] = -pr;
                    }
                }
            }
        }
    }

    cout << unfold(0, n - 1, input, "");

    return 0;
}

string unfold(int L, int R, string input, string num1) {
    const int num2 = fdpPt[L][R];
    if (num2 == 0) return num1 + input.substr(L, R - L + 1);
    if (num2 > 0) return unfold(L + num2, R, input, unfold(L, L + num2 - 1, input, num1));
    return num1 + to_string((R - L + 1) / -num2) + "(" + unfold(L, L - num2 - 1, input, "") + ")";
}