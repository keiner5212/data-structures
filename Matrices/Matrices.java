package Matrices;

public class Matrices {
    /**
     * This program demonstrates basic operations with matrices.
     */
    public static void main(String[] args) {
        // Declaration of matrices
        int[][] matrix1 = {
            {1, 2, 3},
            {4, 5, 6}
        };

        // Printing the matrix
        System.out.println("Result Matrix:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matrix1[i][j] + " ");
            }
            System.out.println();
        }
    }
}
