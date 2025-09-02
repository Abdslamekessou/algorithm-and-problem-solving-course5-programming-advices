#include <iostream>


// 📝 Problem: Write a program that reads a positive number N  
// and prints a letter pattern from 'A' to the Nth letter.  
// 🎯 Example: N = 5  
// Output:  
// A  
// BB  
// CCC  
// DDDD  
// EEEEE  


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



void PrintLetterPattern(int Number){

    cout << "\n";

    for(int i = 65; i <= 65 + Number - 1 ; i++){

        for(int j = 1 ; j <= i - 65 + 1 ; j++){
            cout << char(i) ;
        }

        cout << "\n";

    }

}



int main()
{
    PrintLetterPattern(ReadPositiveNumber("Enter A Positive Number :"));

    return 0;
}
