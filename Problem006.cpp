#include <iostream>

// 🚀 Problem: Write a program to find the sum of digits of a given positive number.  
// ✅ Example: 123 → 1+2+3 = 6


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



int SumOfDigits(int Number){

   int Remainder = 0 , Sum = 0;

    while(Number > 0 ){

       Remainder = Number % 10;
       Number = Number / 10;
       Sum += Remainder;
       
    }

    return Sum;

}



int main()
{
    int sumOfDigits = SumOfDigits(ReadPositiveNumber("Please Enter A Positive Number?"));
    cout << "\nSum Of Digits =  " << sumOfDigits  << endl;

    return 0;
}
