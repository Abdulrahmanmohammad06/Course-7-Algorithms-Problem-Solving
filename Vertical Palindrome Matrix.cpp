#include <iostream>
using namespace std;

void PrintMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

bool IsColumnPalindrome(int matrix[3][3], int rows, int cols)
{
    for (int col = 0; col < cols; col++)
    {
        for (int row = 0; row < rows / 2; row++)
        {
            if (matrix[row][col] != matrix[rows - 1 - row][col])
                return false;
        }
    }
    return true;
}

int main()
{
    int matrix[3][3] = { {1,2,10},{2,2,10},{1,2,10} };

    cout << "\nMatrix\n\n";
    PrintMatrix(matrix, 3, 3);

    if (IsColumnPalindrome(matrix, 3, 3))
        cout << "Yes, is Palindrome" << endl;
    else
        cout << "No, not Palindrome" << endl;

    system("pause>0");
}
