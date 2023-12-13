#include <iomanip>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void delay(void)
{
    int delay;
    delay = 1;
    while (delay < 100000000)
    {
        delay++;
    }
}

// function gotoxy
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int i, j;
    char ulang;

    for (i = 40; i <= 75; i++)
    {
        gotoxy(i, 12);
        printf("-");
        gotoxy(i, 14);
        printf("-");
        delay();
    }

    for (i = 1; i <= 100; i++)
    {
        gotoxy(40, 13);
        cout << "L O A D I N G. . . . " << i << "%";
        delay();
    }
    cout << "\n\n						Loading Complete!" << std::endl;
    system("cls");

    gotoxy(40, 12);
    cout << "    W E L C O M E\n						  to\n 					    CodeRoll Quizz \n";
    cout << "\n			             Press [ enter ] to continue ...?\n";
    getch();
    system("cls");

    struct Question
    {
        string question; // field
        string choiceA;
        string choiceB;
        string choiceC;
        string choiceD;
        char correctAnswer;
        char answer;
    };

    srand(time(NULL));

    // menyiapkan list pertanyaan di array of struct.
    Question questions[] = {
        {
            .question = "Question 1. \nApa output dari kode C++ berikut:\nint arr[5] = {1, 2, "
                        "3, 4, 5};\nint *ptr = arr + 2;\ncout << *(ptr + 1);",
            .choiceA = "2",
            .choiceB = "3",
            .choiceC = "4",
            .choiceD = "5",
            .correctAnswer = 'c',
        },
        {
            .question = "\nQustion 2. \nTypical Range ( -2,147,483,648 to +2,147,483,647 ) "
                        "digunakan pada tipe data?",
            .choiceA = "Short int dan int",
            .choiceB = "unsigned short int dan long int",
            .choiceC = "Int dan long int",
            .choiceD = "Long int dan short int",
            .correctAnswer = 'c',
        },
        {.question = "\nQuestion 3. \nif(data[i] >= count){  simbol Flowchart yang di gunakan pada kode pemograman tersebut adalah? ",
         .choiceA = "Decision",
         .choiceB = "Process",
         .choiceC = "Input/output",
         .choiceD = "Display",
         .correctAnswer = 'a'},
        {.question = "\nQuestion 4. \nDalam c++ tersedia function untuk memeriksa kondisi - kondisi pada operasi file sehingga kesalahan saat eksekusi dapat dikendalikan. Function yang dimaksud adalah? ",
         .choiceA = "Open()",
         .choiceB = "Put()",
         .choiceC = "Get()",
         .choiceD = "Fail()",
         .correctAnswer = 'd'},
        {.question = "\nLast Question \nTerdapat sebuah soal cerita :\n "
                     "\n  Username dan hashed pin dari sebuah PT bocor di sebuah forum hacker, *tenang saja, pinnya sudah di amankan dengan hash function yang kuat,* kata juru bicara PT tersebut.\n"
                     "  Seorang karyawan merasa ada yang janggal dari pernyataan tersebut. Setelah digali lebih dalam, karyawan tersebut mendapati informasi berikut:\n"
                     "- Hash function h yang digunakan adalah : h(k) - k * (k+3) mod 1000003, dimana k adalah key yang ingin dihash\n"
                     "- Pin adalah angka (0-9) dengan tepat N digit\n"
                     "- Sebagian mashed pin ternyata tidak valid, kemungkinan hackernya sengaja merusak sebagian nilainya.\n"
                     "   Dengan data tersebut, bantu karyawan tersebut mendapati PIN semua orang.\n"
                     "\n Dengan syarat input :\n"
                     "- Baris pertama adalah T jumlah cases. 1 <= T <= 100\n"
                     "- T baris berikutnya adalah N dan Hashed PIN, dipisahkan oleh spasi\n"
                     "- 0 <= Hashed pin < 1000003.\n"
                     "\n Dan syarat output :\n"
                     "Untuk masing-masing test case, print 1 baris dengan format case #i: PINS, dimana i adalah nomor test casenya (dimulai dari 1) dan pins adalah kemungkinan PIN\n"
                     "- Jika ada lebih dari satu kemungkinan PIN, tampilkan semuanya dengan dipisahkan spasi, urutkan dari yang paling kecil\n"
                     "- Jika HAshed PIN tidak valid, tampilkan Invalid.\n"
                     "\n Apabila diberikan sampel input :\n"
                     "  5\n"
                     "  1  28\n"
                     "  2  18\n"
                     "  4  10300\n"
                     "  6  10300\n"
                     "  1  5.\n"
                     "\n  Maka output yang akan keluar bernilai :",
         .choiceA = "case #1: 4\n  case #2: 03\n  case #3: 0100\n  case #4: 000100  999900\n  case #5: Invalid\n",
         .choiceB = "case #1: 5\n  case #2: 14\n  case #3: 0110\n  case #4: 000110  999900\n  case #5: 05\n",
         .choiceC = "case #1: Invalid\n  case #2: 63003\n  case #3: 0100\n  case #4: Invalid\n  case #5: Invalid\n",
         .choiceD = "case #1: 4\n  case #2 03\n  case #3: Invalid\n case #4: 000110 999900\n  case #5: Invalid\n",
         .correctAnswer = 'a'}

    };

    // melakukan perulangan sampai jumlah soalnya
    int totalQuestions = 5;
    for (int i = 0; i < totalQuestions; i++)
    {

        cout << "------------------------" << endl;
        // nampipin soalnya
        cout << questions[i].question << endl;

        // nampilin item jawabannya
        cout << "A." << questions[i].choiceA << endl;
        cout << "B." << questions[i].choiceB << endl;
        cout << "C." << questions[i].choiceC << endl;
        cout << "D." << questions[i].choiceD << endl;

        // minta input jawaban lalu taruh di field answer.
        cout << "Tuliskan jawabannya: ";
        cin >> questions[i].answer;

        if (questions[i].answer == questions[i].correctAnswer)
        {
            // ini jika bener
            if (i != totalQuestions - 1)
            {

                char next = 'n';

                while (next == 'n')
                {
                    cout << "Keren banget hyung, lanjut ga nih?\n";
                    cout << "jawab (y/n) : ";
                    cin >> next;
                    if (next == 'n')
                    {
                        return 0;
                    }
                }
            }
        }
        else
        {
            // balik ke soal ini (satu langkah)
            cout << "Jawaban lu salah anjir hyung\n";

            // lempar dadu dulu
            string daduConfirm;
            cout << "Kocok dadu dulu [ketik `y` lalu enter]: ";
            cin >> daduConfirm;

            // proses pelemparan dadu (mengambil nomor random dari 1 - 6)
            int hasilDadu = rand() % 6 + 1; // Get a number 1 to 6
            cout << "Hasil Dadu:" << hasilDadu << endl;

            if (hasilDadu % 2 == 0)
            {
                // hasil dadu genap, maka kembali ke soal yg ini
                cout << "Hasil dadu genap, kerjakan soal ini lagi" << endl;
                i = i - 1;
            }
            else
            {
                // hasil dadu ganjil, maka kembali ke soal yg sebelumnya
                cout << "Hasil dadu ganjil, silahkan kembali ke soal sebelumnya" << endl;
                i = i - 2;
            }
        }
        system("cls");
    }

    system("cls");
    gotoxy(24, 12);
    cout << "C O N G R A T U L A T I O N ! " << std::endl;
    gotoxy(24, 13);
    cout << "You Played Very Well!!!!!!" << endl;
    printf("\n			==========================================================================\n", 16);
    printf("\n				Terimakasih telah bermain\n 				untuk hadiah akan dikirimkan ketika kami sudah jadi miliader.\n", 17);
    printf("\n			==========================================================================", 20);
    delay();
    getch();
    return 0;
}
