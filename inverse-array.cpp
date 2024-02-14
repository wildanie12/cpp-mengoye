#include <iostream>

using namespace std;

int main()
{
    int n;

    // masukin jumlah array
    cin >> n;

    // masukkin ke array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // nampilin arraynya tapi dibalik dari indeks terbesar dulu
    // caranya for loop dari n ke 0
    // n-1 dulu karna dari indeks mulai dari nol
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}