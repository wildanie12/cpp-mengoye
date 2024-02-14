#include <iostream>

using namespace std;

int main()
{
    // deklarasi variable dulu
    int a;
    long int b;
    char c;
    float d;
    double e;

    // input ke variabel itu
    cout << "Masukkin a (int): ";
    cin >> a;
    cout << "Masukkin b (long): ";
    cin >> b;
    cout << "Masukkin c (char): ";
    cin >> c;
    cout << "Masukkin d (float): ";
    cin >> d;
    cout << "Masukkin e (double): ";
    cin >> e;

    // nampilin hasil variabel yang udah di input td
    cout << "Nilai a (int) :" << a << endl;
    cout << "Nilai b (long) :" << b << endl;
    cout << "Nilai c (char) :" << c << endl;
    printf("Nilai d (float): %.3f \n", d);
    printf("Nilai e (double): %.10f \n", e);

    // nampilin jumlah digit dibelakang koma, paling enak pake `printf()`.
    // kasih template string %.10f 10 itu maksudnya 10 dibelakang koma.
}
