#include <iostream>

// 🔢 Print an inverted number pattern from 1 up to i for each row
// 📝 Example: Input = 5
// Output:
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



void printInvertedNumberPattern(int Number){

     cout << "\n";

     for(int i = Number ; i >= 1 ; i--){

        for(int j = 1 ; j <= i ; j++){
            cout << i ;
        }

        cout << "\n";

     }

}


int main()
{
    printInvertedNumberPattern(ReadPositiveNumber("Enter Number :"));
    return 0;
}

