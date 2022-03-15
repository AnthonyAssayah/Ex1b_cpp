#include <iostream>
#include <string>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main()
{
    int rows, cols; 
    char c1, c2;
    cout << "Enter the number of rows: " << endl; 
    cin >> rows; 
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    cout << "Type the first character: " << endl; 
    cin >> c1; 
    cout << "Type the second character: " << endl; 
    cin >> c2;
    try {
        cout << mat(rows, cols, c1, c2) << endl;
    } catch (exception& ex) {
        cout << " Caught exception: " << ex.what() << endl;
    }

    return 0;
}

