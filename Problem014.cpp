#include <iostream>

// 🔠 Print an inverted letter pyramid pattern starting from a given number of rows.
// Each row contains repeated letters, beginning with the last letter and going back to 'A'.
//
// 📝 Example: Input = 3
// Output:
// C C C
// B B
// A

using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



void PrintInvertedLetterPattern(int Number){

     cout << "\n";

     for(int i = 65 + Number -1 ; i >= 65  ; i--){

        for(int j = 1 ; j <= Number - (65 + Number -1 - i) ; j++){
            cout << char(i) ;
        }

        cout << "\n";

     }

}



int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Enter A Number :"));

    return 0;
}
