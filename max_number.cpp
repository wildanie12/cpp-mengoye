#include <iostream>

using namespace std;

// int max_of_four(int a, int b, int c, int d);
// int main() {
//     printf("%d", max_of_four(1, 3, 4, 7));
// }

int max_of_four(int a, int b, int c, int d) {
    int max = 0;

    if (a > max) {
        max = a;
    }
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    return max;
}