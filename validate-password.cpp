#include <iostream>
#include <string.h>

using namespace std;

bool isValid(const string password)
{
    // cek apakah dia sudah 8 karakter atau lebih
    if (password.length() < 8)
    {
        cout << "Passwordnya minimal 8 karakter bang" << endl;
        return false;
    }

    int jumlahHurufBesar = 0;
    int jumlahHurufKecil = 0;
    int jumlahAngka = 0;

    // ngulang-ngulang setiap hurufnya buat di cek & hitung besar kecil sama angkanya.
    for (int i = 0; i < password.length(); i++)
    {
        // cek apakah dia ada satu huruf besar
        if (isupper(password[i]))
        {
            jumlahHurufBesar++;
        }

        // cek apakah dia ada satu huruf kecil
        if (islower(password[i]))
        {
            jumlahHurufKecil++;
        }

        // cek apakah dia ada satu angka
        if (isdigit(password[i]))
        {
            jumlahAngka++;
        }
    }

    // mastiin kalo huruf besar, kecil sama angka gak boleh nol
    if (jumlahHurufBesar == 0)
    {
        cout << "Passwordnya minimal harus ada 1 huruf besar" << endl;
        return false;
    }
    if (jumlahHurufKecil == 0)
    {
        cout << "Passwordnya minimal harus ada 1 huruf kecil" << endl;
        return false;
    }
    if (jumlahAngka == 0)
    {
        cout << "Passwordnya minimal harus ada 1 angka" << endl;
        return false;
    }

    return true;
}

int main()
{
    bool ngeong = isValid("Mengoyee123");

    cout << "Apakah passwordnya valid? " << ngeong << endl;
    return 0;
}