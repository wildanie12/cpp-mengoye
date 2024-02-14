#include <iostream>

using namespace std;

int main() {
    // nyiapin variabel integer x buat dikasih inputan ntar
    int x;

    // nyiapin variabel buat nampung totalnya. kita kasih 0 buat diawal
    int total = 0;

    // selagi ada inputan, tambahin x ke total
    while (cin >> x) {
        total += x;
        i++;
    }

    // tampilin hasil totalnya
    cout << total;
}