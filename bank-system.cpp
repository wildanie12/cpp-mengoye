#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

// blueprint data structure for transaction.
class Transaction
{
public:
    string usernameFrom, usernameTo;
    double amount;
};

// blueprint data structure for user.
class User
{
public:
    string username, password, email, name, address, phone, pin;
    double balance;
    vector<Transaction> transactions;
};

// variable list of users
vector<User> users;

// variable for hold logged user.
User activeUser;

bool login();
void registerUser();
void cekSaldo();
void lihatRiwayat();
void transfer();

int main()
{
    bool active = true;
    while (active)
    {
        int input;
        cout << "|---------------------------------|" << endl;
        cout << "|-----| The Central Bank  |-------|" << endl;
        cout << "|---------------------------------|" << endl;
        cout << "| 1. Login" << endl;
        cout << "| 2. Register" << endl;
        cout << "| 3. Exit" << endl;
        cout << "|--------------" << endl;
        cout << "| Your input: ";
        cin >> input;
        system("cls");

        switch (input)
        {
        case 1:
        {
            bool isSuccessLogin = login();
            if (isSuccessLogin)
            {
                bool sesiLogin = true;
                while (sesiLogin)
                {
                    system("cls");
                    int input2;
                    cout << "|---------------------------------|" << endl;
                    cout << "| Hai " << activeUser.name << ", Selamat datang" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "| 1. Cek Saldo" << endl;
                    cout << "| 2. Lihat Riwayat Transaksi" << endl;
                    cout << "| 3. Transfer Dana" << endl;
                    cout << "| 4. Logout" << endl;
                    cout << "|---------------------------------|" << endl;
                    cout << "| Input: ";
                    cin >> input2;
                    system("cls");
                    switch (input2)
                    {
                    case 1:
                        cekSaldo();
                        break;
                    case 2:
                        lihatRiwayat();
                        break;
                    case 3:
                        transfer();
                        break;
                    case 4:
                        sesiLogin = false;
                        break;
                    }
                    system("cls");
                }
            }
        }
        break;
        case 2:
            registerUser();
            break;
        case 3:
            active = false;
            break;
        }

        system("cls");
    }
}

bool login()
{
    // Bagian login silahkan ngoding disini

    // deklarasi variabel
    string username, password;

    // input login
    cout << "Masukkan username anda: ";
    cin >> username;
    cout << "Masukkan password anda: ";
    cin >> password;

    // cek satu-satu di variabel global `users`
    for (const User &user : users)
    {
        if (user.username == username && user.password == password)
        {
            activeUser = user;

            cout << "Login sukses" << endl;
            cout << "Press Enter to Continue";
            getch();
            return true;
        }
    }

    cout << "Ngasal aja klean ni, yg bener apa login tuh" << endl;
    cout << "Press Enter to Continue";
    getch();
    return false;
}

void registerUser()
{
    // Bagian register user silahkan ngoding disini

    // deklarasi variable
    string username, password, email, name, address, phone, pin;

    // input data user
    cout << "Masukkan username anda:";
    cin >> username;
    cout << "Masukkan password anda:";
    cin >> password;
    cout << "Masukkan email anda:";
    cin >> email;
    cout << "Masukkan name anda:";
    cin >> name;
    cout << "Masukkan address anda:";
    cin >> address;
    cout << "Masukkan phone anda:";
    cin >> phone;
    cout << "Masukkan pin anda:";
    cin >> pin;

    // masukan data user ke variabel global `users`
    User user;
    user.username = username;
    user.password = password;
    user.email = email;
    user.name = name;
    user.address = address;
    user.phone = phone;
    user.balance = 0;
    user.pin = pin;
    users.push_back(user);

    cout << "Press Enter to Continue";
    getch();
}

void cekSaldo()
{
    cout << "Hai " << activeUser.name << endl;
    cout << "Saldo kamu tinggal segini" << activeUser.balance << endl;
    // Bagian cek saldo user silahkan ngoding disini

    cout << "Press Enter to Continue";
    getch();
}

void lihatRiwayat()
{
    cout << "Ini lihat riwayat" << endl;
    // Bagian lihat riwayat user silahkan ngoding disini

    // for (const Transaction &tr : activeUser.transactions)
    // {
    //     cout << tr.usernameFrom << endl;
    //     cout << tr.usernameTo << endl;
    //     cout << tr.amount << endl;
    // }

    cout << "Press Enter to Continue";
    getch();
}

void transfer()
{
    cout << "Ini transfer" << endl;
    // Bagian transfer user silahkan ngoding disini

    // 1. terima inputan (username yang akan ditransfer & amountnya)
    // 2. cari username yang akan di transfer di `users`
    // 3. bikin transaction lalu tambahkan di activeUser sebagai riwayat
    // 4. kurangin saldo activeUser, tambahin saldo userTo

    // User userTo;
    // for (const User &user : users)
    // {
    //     if (user.username == "inputanuser")
    //     {
    //         userTo = user;
    //     }
    // }

    // Transaction tr1;
    // tr1.usernameFrom = activeUser.username;
    // tr1.usernameTo = "";
    // tr1.amount = 123;

    // activeUser.transactions.push_back(tr1);
    // activeUser.balance -= 123;
    // userTo.balance += 123;

    cout << "Press Enter to Continue";
    getch();
}