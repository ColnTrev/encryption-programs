/// Encryption Problem Solution
/// This code is a solution to the problem posed at
/// https://www.hackerrank.com/challenges/encryption
///
/// This program takes the message written and removes spaces, then calculates
/// a grid whose rows and columns such that:
/// floor(sqrt(length)) <= rows <= columns <= ceil(sqrt(length))
/// There are potentially many options of grids, however there are extraneous
/// options. These are taken care of by dividing the length of the message by
/// the number of columns and taking the ceiling value of that number. This
/// ensures the best solution is used every time.
///
/// In outputting the message, the two dimesional array is avoided by
/// the offset of each character that would be in a column. So, rather than
/// use precious memory to store a whole two dimensional array, we can get the
/// same "grid" using the offsets in the single dimension array.
///
/// This program has been modified from its original version to accept user
/// input.
///
/// author: Collin Gordon
/// file: encryption.cpp

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    string message; // the message entered by the user
    int lnth;       // a variable to store the length of the message
    int rows;       // the number of rows in the grid
    int columns;    // the number of columns in the grid
    
    // getting user input
    cout << "Enter in a message: ";
    getline(cin, message);
    
    // removing spaces
    message.erase(remove(message.begin(), message.end(), ' '), message.end());
    
    // calculating grid
    lnth = message.length();
    columns = ceil(sqrt(lnth));
    rows    = ceil(message.length()/columns);
    
    // outputting message
    for(int i = 0; i < columns; i++){
        
        for(int j = 0; j <= rows; j++){
            
            if(j*columns + i < lnth){
                cout << message[j*columns + i];
            }
            
        }
        
        cout << ' ';
    }
    
    cout << endl;
    
    return EXIT_SUCCESS;
}
