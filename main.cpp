#include <iostream>
#include <string>
#include "mat.hpp"
using namespace std;


namespace ariel {
    int main()
    {
        int rows, cols; 
        char c1, c2;
        cout << "Enter the number of rows: "; 
        cin >> rows; 
        cout << "Enter the number of cols: ";
        cin >> cols;
        cout << "Type the first character: "; 
        cin >> c1; 
        cout << "Type the second character: "; 
        cin >> c2;
        mat(rows, cols, c1, c2);

        return 0;
    }
