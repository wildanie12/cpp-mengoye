#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

const int delay = 5;
const int matrixWidth = 23;
const int matrixHeight = 23;
char matrix[matrixHeight][matrixWidth] = {
    {'A', 'A', 'F', 'L', 'K', 'H', 'P', 'F', 'S', 'S', 'U', 'F', 'I', 'C', 'I', 'C', 'L', 'E', 'S', 'G', 'N', 'N', 'H'},
    {'S', 'F', 'V', 'R', 'E', 'O', 'M', 'R', 'W', 'L', 'R', 'T', 'T', 'S', 'X', 'O', 'Q', 'Q', 'N', 'A', 'O', 'A', 'O'},
    {'Q', 'E', 'I', 'A', 'I', 'F', 'X', 'A', 'E', 'I', 'R', 'F', 'V', 'F', 'Y', 'S', 'X', 'I', 'M', 'I', 'N', 'J', 'I'},
    {'W', 'S', 'T', 'R', 'L', 'G', 'O', 'C', 'A', 'P', 'B', 'I', 'A', 'F', 'I', 'W', 'I', 'W', 'T', 'U', 'A', 'C', 'M'},
    {'F', 'E', 'Y', 'A', 'E', 'A', 'I', 'S', 'T', 'P', 'C', 'R', 'L', 'U', 'J', 'K', 'O', 'A', 'K', 'C', 'E', 'R', 'S'},
    {'R', 'V', 'D', 'A', 'K', 'P', 'N', 'D', 'E', 'E', 'H', 'D', 'E', 'M', 'S', 'N', 'C', 'K', 'K', 'F', 'O', 'A', 'H'},
    {'M', 'R', 'N', 'E', 'D', 'S', 'L', 'C', 'R', 'R', 'I', 'W', 'N', 'R', 'S', 'A', 'A', 'F', 'I', 'T', 'M', 'M', 'I'},
    {'Y', 'A', 'A', 'E', 'C', 'I', 'E', 'A', 'H', 'Y', 'M', 'O', 'T', 'A', 'V', 'H', 'R', 'S', 'S', 'T', 'I', 'S', 'B'},
    {'R', 'J', 'S', 'E', 'W', 'E', 'L', 'C', 'C', 'E', 'N', 'N', 'I', 'E', 'T', 'O', 'H', 'W', 'S', 'G', 'L', 'S', 'E'},
    {'A', 'T', 'A', 'N', 'Y', 'Y', 'M', 'O', 'I', 'E', 'E', 'S', 'N', 'E', 'S', 'I', 'O', 'I', 'R', 'E', 'L', 'T', 'R'},
    {'U', 'T', 'E', 'N', 'E', 'W', 'E', 'B', 'H', 'M', 'Y', 'B', 'E', 'T', 'N', 'N', 'R', 'A', 'I', 'E', 'B', 'E', 'N'},
    {'R', 'C', 'L', 'K', 'U', 'T', 'E', 'A', 'E', 'Q', 'J', 'L', 'S', 'G', 'S', 'H', 'T', 'G', 'D', 'S', 'K', 'O', 'A'},
    {'B', 'H', 'O', 'I', 'C', 'A', 'T', 'N', 'R', 'R', 'S', 'D', 'D', 'E', 'C', 'E', 'H', 'O', 'O', 'L', 'G', 'I', 'T'},
    {'E', 'N', 'S', 'L', 'U', 'A', 'R', 'I', 'R', 'S', 'E', 'T', 'A', 'L', 'O', 'C', 'O', 'H', 'C', 'T', 'O', 'H', 'E'},
    {'F', 'Z', 'F', 'U', 'D', 'Q', 'J', 'Y', 'M', 'A', 'D', 'O', 'Y', 'I', 'W', 'Y', 'G', 'L', 'O', 'V', 'E', 'S', 'U'},
    {'T', 'E', 'K', 'A', 'L', 'F', 'W', 'O', 'N', 'S', 'N', 'A', 'E', 'B', 'M', 'I', 'E', 'J', 'T', 'Z', 'N', 'T', 'G'},
    {'E', 'S', 'W', 'P', 'O', 'S', 'J', 'X', 'E', 'U', 'T', 'U', 'Y', 'O', 'Z', 'U', 'W', 'A', 'K', 'E', 'Z', 'H', 'M'},
    {'K', 'Z', 'U', 'H', 'B', 'P', 'E', 'Z', 'E', 'E', 'R', 'F', 'L', 'M', 'S', 'N', 'O', 'W', 'B', 'A', 'L', 'L', 'H'},
    {'N', 'S', 'N', 'O', 'W', 'B', 'O', 'A', 'R', 'D', 'Y', 'T', 'V', 'W', 'Y', 'C', 'L', 'E', 'V', 'O', 'H', 'S', 'A'},
    {'A', 'C', 'O', 'C', 'R', 'Q', 'L', 'G', 'Z', 'I', 'Y', 'C', 'H', 'O', 'D', 'R', 'A', 'Z', 'Z', 'I', 'L', 'B', 'I'},
    {'L', 'B', 'V', 'K', 'K', 'W', 'A', 'N', 'Z', 'A', 'A', 'Q', 'I', 'N', 'W', 'O', 'L', 'P', 'W', 'O', 'N', 'S', 'L'},
    {'B', 'F', 'R', 'E', 'E', 'Z', 'I', 'N', 'G', 'R', 'A', 'I', 'N', 'S', 'L', 'I', 'L', 'G', 'T', 'M', 'E', 'L', 'T'},
    {'H', 'Q', 'P', 'Y', 'L', 'W', 'H', 'F', 'M', 'N', 'F', 'F', 'U', 'F', 'P', 'S', 'W', 'X', 'N', 'U', 'M', 'M', 'V'}};

struct Result
{
    int row;
    int col;
    string message;
    bool isFound;
};

Result isFoundInMatrix(string word, int lengthWord);
int main()
{

    int totalQuestion;
    cin >> totalQuestion;

    string questions[totalQuestion];
    for (int i = 0; i < totalQuestion; i++)
    {
        cin >> questions[i];
    }

    Result results[totalQuestion];
    for (int i = 0; i < totalQuestion; i++)
    {
        results[i] = isFoundInMatrix(questions[i], static_cast<int>(questions[i].length()));
    }

    for (int i = 0; i < totalQuestion; i++)
    {
        printf("%s\n", results[i].message.c_str());
    }

    return 0;
}

Result isFoundInMatrix(string word, int lengthWord)
{
    // ----------------------------
    // check horizontal
    // ----------------------------
    for (int row = 0; row < matrixHeight; row++)
    {
        for (int col = 0; col <= matrixWidth - lengthWord; col++)
        {
            bool isMatched = true;
            printf("\nHORIZONTAL SEARCHING\n");
            printf("checking row %d col %d => ", row, col);
            for (int x = 0; x < lengthWord; x++)
            {
                printf("%c ", matrix[row][col + x]);
                if (matrix[row][col + x] != word[x])
                {
                    isMatched = false;
                }
            }
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(delay));
            system("clear");

            if (isMatched)
            {
                return (Result){
                    .row = row,
                    .col = col,
                    .message = "The word '" + word + "' is found horizontally " + to_string(row) + ", " + to_string(col),
                    .isFound = true,
                };
            }
        }
    }

    // ----------------------------
    // check vertical
    // ----------------------------
    for (int col = 0; col < matrixWidth; col++)
    {
        for (int row = 0; row <= matrixHeight - lengthWord; row++)
        {
            bool isMatched = true;
            printf("\nVERTICAL SEARCHING\n");
            printf("checking col %d row %d => ", col, row);
            for (int x = 0; x < lengthWord; x++)
            {
                printf("%c ", matrix[row + x][col]);
                if (matrix[row + x][col] != word[x])
                {
                    isMatched = false;
                }
            }
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(delay));
            system("clear");

            if (isMatched)
            {
                return (Result){
                    .row = row,
                    .col = col,
                    .message = "The word '" + word + "' is found vertically " + to_string(row) + ", " + to_string(col),
                    .isFound = true,
                };
            }
        }
    }

    // ----------------------------
    // check diagonal
    // ----------------------------
    for (int row = 0; row <= matrixHeight - lengthWord; row++)
    {
        for (int col = 0; col <= matrixWidth - lengthWord; col++)
        {
            bool isMatched = true;
            printf("\nDIAGONAL SEARCHING\n");
            printf("checking row %d col %d => ", row, col);
            for (int x = 0; x < lengthWord; x++)
            {
                printf("%c ", matrix[row + x][col + x]);
                if (matrix[row + x][col + x] != word[x])
                {
                    isMatched = false;
                }
            }
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(delay));
            system("clear");

            if (isMatched)
            {
                return (Result){
                    .row = row,
                    .col = col,
                    .message = "The word '" + word + "' is found diagonally on " + to_string(row) + ", " + to_string(col),
                    .isFound = true,
                };
            }
        }
    }
    return (Result){
        .row = 0,
        .col = 0,
        .message = "The word '" + word + "' is notfound on the matrix",
        .isFound = false,
    };
}