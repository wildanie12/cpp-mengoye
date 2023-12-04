#include <iostream>

using namespace std;

struct User
{
    string nama;
    int umur;
    string alamat;
};

struct Buku
{
    string judul;
    string sinopsis;
    int eksemplar;
};

int main()
{
    User orang1;
    orang1.nama = "Firda";
    orang1.umur = 21;
    orang1.alamat = "Jakarta";

    Buku buku1;
    buku1.judul = "Mencari nafkah modal hape doang";
    buku1.sinopsis = "Nganu";
    buku1.eksemplar = 700;

    cout << "nama: " << orang1.nama << endl;
    cout << "umur: " << orang1.umur << endl;
    cout << "alamat: " << orang1.alamat << endl;
    cout << "-----------------------" << endl;
    cout << "judul: " << buku1.judul << endl;
    cout << "sinopsis: " << buku1.sinopsis << endl;
    cout << "eksemplar: " << buku1.eksemplar << endl;
}