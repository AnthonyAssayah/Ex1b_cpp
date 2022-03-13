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
        const int minNum=33;
        const int maxNum=126;

        if(c1<minNum || c2<minNum || c1>maxNum || c2>maxNum){
            throw invalid_argument(" Char not in range");
        }
        if (rows % 2 == 0 || cols % 2 == 0) {
            throw invalid_argument(" Rows and Cols must be odd numbers !");
        }
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument(" Rows and Cols must be postive numbers !");
        }

//     char mat[rows][cols];
        vector <vector<char>> mat(rows, vector<char>(cols));
        int k = 0; int l = 0;
        int r = rows; int c = cols;
        int n = 0;
        char curr = c1;
        while (k < r && l < c) {

            // Fill the first row from the remaining rows
            for (int i = l; i < c; i++) {
                mat[l][i] = curr;
            }

            // Fill the last column from the remaining columns
            for (int i = k; i < r; i++) {
                mat[i][c - 1] = curr;
            }

            // Fill the last row from the remaining rows
            if (k < r) {

                for (int i = l; i <= c - 1; i++) {
                    mat[r - 1][i] = curr;
                }
            }

            //Print the first column from the remaining columns
            if (l < c) {

                for (int i = k; i <= r - 1; i++) {
                    mat[i][l] = curr;
                }

            }

            // Change character in each iteration
            n++;
            (n % 2 == 0) ? curr = c1 : curr = c2;

            k++;
            l++;
            c--;
            r--;

        }
        string ans;
        // Print the matrix
        for (int i = 0; i < rows; i++) {
            string cur;
            for (int j = 0; j < cols; j++) {
                cur += mat[i][j];
//			ans.push_back(mat[i][j]);
                //cout << endl;
            }
            cur += "\n";
            ans += cur;
        }

        return ans;
    }
}

