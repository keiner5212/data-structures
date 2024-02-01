#include <iostream>
using namespace std;

/**
 * @brief This program demonstrates basic operations with matrices.
 * @return 0 indicating successful execution.
 */
int main()
{
    // Declaration of matrices
    int matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // Printing the matrix
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
