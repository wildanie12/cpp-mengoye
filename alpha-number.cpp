#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    switch(n) {
        case 1:
            cout << "satu";
            break;
        case 2:
            cout << "dua";
            break;
        case 3:
            cout << "tiga";
            break;
        case 4:
            cout << "empat";
            break;
        case 5:
            cout << "lima";
            break;
        case 6:
            cout << "enam";
            break;
        case 7:
            cout << "tujuh";
            break;
        case 8:
            cout << "delapan";
            break;
        case 9:
            cout << "sembilan";
            break;
        default:
            cout << "Lebih dari 9";
            break;
    }
}