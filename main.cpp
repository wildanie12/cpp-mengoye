#include <iostream>

using namespace std;

int rollDie()
{
    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = 6; // this->dieSize; // the max value is the die size

    roll = rand() % (max - min + 1) + min;

    return roll;
}

struct Question
{
    string question;
    string choiceA;
    string choiceB;
    string choiceC;
    string choiceD;
    char correctAnswer;
};

int main()
{
    cout << "Dadu dimainkan:";
    cout << rollDie() << endl;
    string soal[5] = {
        "Ini soal pertama.. jawab hayo?\n a.) Anu \n b.) oye \n c.) ngok",
        "Ini soal kedua.. jawab hayo?",
        "Ini soal ketiga.. jawab hayo?",
    };

    string input[5] = {};

    Question questions[] = {
        {
            question : "2. Typical Range ( -2,147,483,648 to +2,147,483,647) digunakan pada tipe data?",
            choiceA : "Short int dan int",
            choiceB : "unsigned short int dan long int",
            choiceC : "Int dan long int",
            choiceD : "Long int dna short int",
            correctAnswer : 'c',
        },
        {
            question : "if(data[i] >= count){  simbol Flowchart yang di gunakan pada kode pemograman tersebut adalah? ",
            choiceA : "Decision",
            choiceB : "Process",
            choiceC : "Input/output",
            choiceD : "Display",
            correctAnswer : 'a'
        },
        {
            question : "Apa output dari kode C++ berikut:\nint arr[5] = {1, 2, 3, 4, 5};\nint *ptr = arr + 2;\ncout << *(ptr + 1);",
            choiceA : "2",
            choiceB : "3",
            choiceC : "4",
            choiceD : "5",
            correctAnswer : 'b',
        },
    };

    for (int i = 0; i < 5; i++)
    {
        cout << soal[i] << i << endl;
        cout << "Tuliskan jawabannya: ";
        cin >> input[i];

        if (input[i] == "a")
        {
            // ini bener
            cout << "Mantap mang, lanjut\n";
        }
        else
        {
            // balik ke soal ini (satu langkah)
            cout << "Jawaban salah anjir\n";
            i = i - 1;
        }

        if (i > 0)
        {
            cout << " mo balik?";
            string balik;
            cin >> balik;
            if (balik == "y" && i > 0)
            {
                // balik ke soal sebelumnya (dua langkah)
                i = i - 2;
            }
        }
    }

    return 0;
}
