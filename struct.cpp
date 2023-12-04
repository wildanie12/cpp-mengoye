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
    User dataOrang[] = {
        {nama : "Firda", umur : 21, alamat : "Jakarta"},
        {nama : "Wawan", umur : 17, alamat : "Semarang"},
    };

    cout << "nama: " << dataOrang[0].nama << endl;
    cout << "umur: " << dataOrang[0].umur << endl;
    cout << "alamat: " << dataOrang[0].alamat << endl;
    cout << "---" << endl;
    cout << "nama: " << dataOrang[1].nama << endl;
    cout << "umur: " << dataOrang[1].umur << endl;
    cout << "alamat: " << dataOrang[1].alamat << endl;

    User orang1 = {
        nama : "Budi",
        umur : 19,
        alamat : "Bogor",
    };
    cout << "---" << endl;
    cout << "nama: " << orang1.nama << endl;
    cout << "umur: " << orang1.umur << endl;
    cout << "alamat: " << orang1.alamat << endl;

    cout << "-----------------------" << endl;

    Buku buku1;
    buku1.judul = "Mencari nafkah modal hape doang";
    buku1.sinopsis = "Nganu";
    buku1.eksemplar = 700;

    cout << "judul: " << buku1.judul << endl;
    cout << "sinopsis: " << buku1.sinopsis << endl;
    cout << "eksemplar: " << buku1.eksemplar << endl;
}