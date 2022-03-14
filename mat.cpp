#include <iostream>
#include <string>
#include "mat.hpp"
#include <vector>

using namespace std;

namespace ariel {
    string mat(int rows1, int cols1, char c1, char c2) {

        // Change position of the two first arguments rows and cols
        int rows = cols1;
        int cols = rows1;
        const int min_char=33;  // ascii value for '!'
        const int max_char=126; // ascii value for '~'

        // Throw exceptions for invalid characters
        if(c1<min_char || c2<min_char || c1>max_char || c2>max_char){
            throw invalid_argument(" c1 or c2 is not in range !");
        }
        if (rows % 2 == 0 || cols % 2 == 0) {
            throw invalid_argument(" Rows and Cols must be odd numbers !");
        }
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument(" Rows and Cols must be positive numbers !");
        }

        // Define dynamic arrays to store the characters
        vector <vector<char>> mat(rows, vector<char>(cols));

        /* first_row - index for the first row of the carpet
         * first_col - index for the first col of the carpet
         * last_row  - index for the last row of the carpet
         * last_col  - index for the last col of the carpet
        */
        
        int first_row = 0; int first_col = 0;
        int last_row = rows; int last_col = cols;

        // index - size of the matrix (carpet) for each iteration
        int n = 0;
        char curr_char = c1;
        while (first_row < last_row && first_col < last_col) {

            // Fill the first row from the remaining rows
            for (int i = first_col; i < last_col; i++) {
                mat[first_col][i] = curr_char;
            }

            // Fill the last column from the remaining columns
            for (int i = first_row; i < last_row; i++) {
                mat[i][last_col - 1] = curr_char;
            }

            // Fill the last row from the remaining rows
            if (first_row < last_row) {

                for (int i = first_col; i <= last_col - 1; i++) {
                    mat[last_row - 1][i] = curr_char;
                }
            }

            //Print the first column from the remaining columns
            if (first_col < last_col) {

                for (int i = first_row; i <= last_row - 1; i++) {
                    mat[i][first_col] = curr_char;
                }

            }

            // Change character in each iteration
            n++;
            (n % 2 == 0) ? curr_char = c1 : curr_char = c2;

            first_row++;
            first_col++;
            last_col--;
            last_row--;

        }
        string ans;
        // Insert the characters into the matrix
        for (int i = 0; i < rows; i++) {
            string cur;
            for (int j = 0; j < cols; j++) {
                cur += mat[i][j];
            }
            cur += "\n";
            ans += cur;
        }

        return ans;
    }
}


