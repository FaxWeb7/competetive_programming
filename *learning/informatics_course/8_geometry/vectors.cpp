#include <iostream>
using namespace std;

struct r {
    int x ,y;
    double len() {
        return hypot(x, y);
    }
    double angle() { //подсчет угла вектора в радинах (для градусов нужно домножить на 180/pi)
        return atan2(y, x); // arctg
    }

    r(int x, int y) : x(x), y(y) {}
};

int operator*(r a, r b) { // перегрузка оператора для подсчета скалярного произведения
    return a.x*b.x + a.y*b.y;
}
int operator%(r a, r b) { // перегрузка оператора для подсчета векторного произведения
    return a.x*b.y - b.x*a.y; 
}
double angle(r a, r b) { // подсчет угла между двумя векторами
    return atan2(a % b, a * b);
}


int main(){
    r vec1(3, 2);
    r vec2(1, 4);
    cout << vec1.len() << ' ' << vec1.angle() << '\n';

    cout << vec1 * vec2 << ' ' << vec1 % vec2 << ' ' << angle(vec1, vec2);

    return 0;
}