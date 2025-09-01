#include <iostream>

// 🔢 Print a pyramid number pattern where each row repeats the row number
// 📝 Example: Input = 5
// Output:
// 1
// 22
// 333
// 4444
// 55555


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



void PrintNumberPattern(int Number){

     cout << "\n";

     for(int i = 1 ; i <= Number ; i++){

        for(int j = 1 ; j <= i ; j++){
            cout << i ;
        }

        cout << "\n";

     }

}


int main()
{
  
    PrintNumberPattern(ReadPositiveNumber("Enter A Number :"));

    return 0;
}
