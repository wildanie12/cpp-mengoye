#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));
    cout << (rand() % 6 + 1) << endl;
    int r = rand() % 6 + 1; // Get a number 1 to 6
    cout << "Hasil lempar dadu: " << r << " ";
    return 0;
}