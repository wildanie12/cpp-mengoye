#include <iostream>

using namespace std;

int main() {
    // bikin variabel buat tar di inputin
    int n;

    // inputin ke n
    cin >> n;

    // bikin perulangan sebanyak n kali (dari 1 -> 10)
    for (int i = 1; i <= n; i++) {
        // kalo belakangnya 3 tampilin "nice"
        if (i % 10 == 3) {
            cout << "Nice" << endl;
            continue;
        }

        // kalo kelipatan 5 kacangin aja, lanjut
        if (i % 5 == 0) {
            continue;
        }

        cout << i << endl;
    }
}