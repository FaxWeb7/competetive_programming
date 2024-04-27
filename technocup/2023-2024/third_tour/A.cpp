#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    unsigned long long n;
    scanf("%llu", &n);

    if (n%2ULL == 0ULL) printf("%llu", n);
    else printf("%llu", n-(n%2ULL));
}