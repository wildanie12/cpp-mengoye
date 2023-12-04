#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));
    int r = rand() % 6 + 1; // Get a number 1 to 6
    cout << "Hasil lempar dadu" << r << " ";
    return 0;
}