#include <iostream>
using namespace std;

int f (int x){
    // возвращает y по x
    return 1;
}

int main(){
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 300; ++i){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if (f(m1) < f(m2)){
            r = m2;
        } else {
            l = m1;
        }
    }

    return 0;
}