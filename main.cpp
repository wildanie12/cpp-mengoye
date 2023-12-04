#include <iomanip>
#include <iostream>

using namespace std;

struct Question {
  string question; // field
  string choiceA;
  string choiceB;
  string choiceC;
  string choiceD;
  char correctAnswer;
  char answer;
};

int main() {
  srand(time(NULL));

  // menyiapkan list pertanyaan di array of struct.
  Question questions[] = {
      {
        .question = "1. Apa output dari kode C++ berikut:\nint arr[5] = {1, 2, "
                   "3, 4, 5};\nint *ptr = arr + 2;\ncout << *(ptr + 1);",
        .choiceA = "2",
        .choiceB = "3",
        .choiceC = "4",
        .choiceD = "5",
        .correctAnswer = 'b',
      },
      {
        .question = "3. Typical Range ( -2,147,483,648 to +2,147,483,647) "
                   "digunakan pada tipe data?",
        .choiceA = "Short int dan int",
        .choiceB = "unsigned short int dan long int",
        .choiceC = "Int dan long int",
        .choiceD = "Long int dna short int",
        .correctAnswer = 'c',
      },
      {
        .question = "2. if(data[i] >= count){  simbol Flowchart yang di gunakan "
                   "pada kode pemograman tersebut adalah? ",
        .choiceA = "Decision",
        .choiceB = "Process",
        .choiceC = "Input/output",
        .choiceD = "Display",
        .correctAnswer = 'a'
      },
  };

  // melakukan perulangan sampai jumlah soalnya
  for (int i = 0; i < 3; i++) {
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

    if (questions[i].answer == questions[i].correctAnswer) {
      // ini jika bener
      cout << "Mantap mang, lanjut\n";
    } else {
      // balik ke soal ini (satu langkah)
      cout << "Jawaban salah anjir\n";

      // lempar dadu dulu
      string daduConfirm;
      cout << "Kocok dadu dulu [ketik `y` lalu enter]: ";
      cin >> daduConfirm;

      // proses pelemparan dadu (mengambil nomor random dari 1 - 6)
      int hasilDadu = rand() % 6 + 1; // Get a number 1 to 6
      cout << "Hasil Dadu:" << hasilDadu << endl;

      if (hasilDadu % 2 == 0) {
        // hasil dadu genap, maka kembali ke soal yg ini
        cout << "Hasil dadu genap, kerjakan soal ini lagi" << endl;
        i = i - 1;
      } else {
        // hasil dadu ganjil, maka kembali ke soal yg sebelumnya
        cout << "Hasil dadu ganjil, silahkan kembali ke soal sebelumnya"
             << endl;
        i = i - 2;
      }
    }
  }

  return 0;
}
