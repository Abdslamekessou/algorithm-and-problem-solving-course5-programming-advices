#include <iostream>

// 📌 Problem: Read a positive number from the user and print its digits in reverse order.
// ✨ Example: Input = 123 → Output = 3 2 1 (each digit on a new line).

using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



void PrintDigits(int Number){

   int Remainder = 0;

    while(Number > 0 ){

       Remainder = Number % 10;
       Number = Number / 10;
       cout << Remainder <<endl;
    }

}



int main()
{

    PrintDigits(ReadPositiveNumber("Please Enter A Positive Number?"));

    return 0;
}
