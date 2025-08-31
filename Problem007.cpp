#include <iostream>

// 🚀 Problem: Write a program to reverse the digits of a given positive number.
// ✅ Example: Input = 1234 → Output = 4321

using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



int ReverseNumber(int Number){

   int Remainder = 0 , reverseNum = 0;

    while(Number > 0 ){

       Remainder = Number % 10;
       reverseNum = reverseNum * 10 + Remainder ;
       Number = Number / 10;

    }
  
    return reverseNum;
}



int main()
{
    int reverseNumber = ReverseNumber(ReadPositiveNumber("Please Enter A Positive Number?"));

    cout <<"\nReverse is : " << reverseNumber <<endl ;

    return 0;
}
