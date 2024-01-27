#include <iostream>

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;

    if (n1 % 2 != 0) {
        std::cout << -1 << std::endl;
    } else {
        int vertices = n1;
        int type = n1 / 2;
        if (n1 != n2) {
            vertices = n2;
            type = n2 / 2;
        }
        std::cout << vertices << " " << type << std::endl;
    }

    return 0;
}
