#include <iostream>
#include <vector>

using namespace std;

int solution(string &a, string &b){
    int n = a.size(), m = b.size();
    if (n != m) return -1;

    int ans = 0;
    while (ans <= n){
        string newA = a;
        for (int i = 0; i < n; ++i){
            newA[(i + ans) % n] = a[i];
        }
        
        if (newA == b) return ans;
        ans++;
    }

    return -1;
}

int main(){
    string a, b;
    cin >> a >> b;

    cout << solution(a, b);

    return 0;
}