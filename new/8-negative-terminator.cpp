#include <iostream>

using namespace std;

int main()
{

    // sama kayak nomor 6
    // kita bikin variabel buat nyimpen inputannya
    int x;

    // ini variabel buat nyimpen totalnya tar
    int mengoye = 0;

    // selagi ada inputan, tambahin ke total
    while (cin >> x)
    {
        // kalo yang diinputin negatif, yaudah break aja
        if (x < 0)
        {
            break;
        }
        // masukkin ke total
        mengoye += x;
    }

    // sajikan ke layar ygy
    cout << mengoye;
}