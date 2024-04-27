#include <iostream>
#include <vector>
using namespace std;
using ld = long double;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    ld m;
    scanf("%d%d%Lf", &n, &k, &m);
    vector<ld> a;
    a.reserve(n);
    for (int i = 0; i < n; i++){
        ld num;
        scanf("%Lf", &num);
        a.push_back(num);
    }

    int ans = 0;
    ld numsSum = 0;
    int numsSize = 0;
    for (int i = 0; i < n; i++){
        if (numsSize < k+1){
            numsSum += a[i];
            numsSize++;
        }
        else {
            if (numsSum == m){
                ans = i-k;
                break;
            }
            numsSum -= a[i-k-1];
            numsSum += a[i];
        }
        if (i == n-1 && numsSum == m) ans = i-k+1;
    }
    printf("%d", ans);

    return 0;
}
