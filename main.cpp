#include <iostream>
#include <string.h>
using namespace std;


string mat(int rows1, int cols1, char c1, char c2)
{

	// Change position of the two first arguments rows and cols
	int rows = cols1;
	int cols = rows1;
	
     if (rows % 2 == 0 || cols % 2 == 0) {
          throw invalid_argument(" Rows and Cols must be odd numbers !");
     }
     else if ( rows < 0 || cols < 0) {
          throw invalid_argument(" Rows and Cols must be postive numbers !");
     }

     char mat[rows][cols];
	int k = 0, l = 0;
	int r = rows, c = cols;
     int n =0;
     char curr = c1;
	while (k < c && l < r) {

		// Fill the first row from the remaining rows 
		for (int i = l; i < c; i++) {
			mat[l][i] = curr;
          }

		// Fill the last column from the remaining columns 
		for (int i = k; i < r; i++) {
			mat[i][c-1] = curr;
          }

		// Fill the last row from the remaining rows 
		if (k < r) {

			for (int i = l; i <= c-1; i++) {
				mat[r-1][i] = curr;
               }
		}

		//Print the first column from the remaining columns 
		if (l < c) {

			for (int i = k; i <= r-1; i++) {
			    mat[i][l] = curr;
               }

		}

		// Change character in each iteration
          n++;
          (n%2 == 0)? curr = c1 : curr = c2;

          k++;
          l++;
          c--;
          r--;

	}
	string ans = "";
	string str = "";
	cout << "string ans = " << ans;
	// Print the matrix
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			cout <<" "<< mat[i][j];
			ans.push_back(mat[i][j]);
			//cout << endl;
        }
        ans+="\n";
		cout << endl;
	}

	return ans;
}




/* Driver program to test above functions */
int main()
{
	// puts("COLS = 3 ROWS = 3");
     mat(3, 15, '~', '=');

	return 0;
}


// void mat(int row, int col, char sym1, char sym2){

//      char arr[row][col];
//      int inc = 0;
//      int x = row;
//      int y = col;

//      while ( x >= 0 && y >= 0){
//            cout << "x is equal to " << x << endl;
//            cout << "y is equal to " << y << endl;
//           for (int i = 0; i <= x; i++){
//                for (int j = 0; j <= y; j++) {
//                     if ((i == 0) || (i == x) || (j == 0) || (j == y)) {
//                          arr[i][j] = sym1;
//                         // cout << arr[i][j] <<" "; 
//                         // printMatrix(arr[x][y]);
                        
//                          cout << "1) -inc is equal to " << inc << endl;
//                     }
//                     else if (inc % 2 == 0) {
//                          arr[i+inc][j+inc] = sym1;
//                          cout << arr[i][j] <<" "; 
//                          cout << "2) -inc is equal to " << inc << endl;
                                              
//                     }
//                     else if (inc % 2 == 1) {
//                          arr[i+inc][j+inc] = sym2;
//                          cout << arr[i][j] <<" "; 
//                          cout << "3) -inc is equal to " << inc << endl;
//                     }
//                }
//           }
//            x = x -2;
//            y = y -2;
//           cout << endl;
//           inc++;
//      }
// }