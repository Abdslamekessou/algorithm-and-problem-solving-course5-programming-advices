#include <iostream>

// 🔢 Program to read a positive number and print its digits in order (from left to right).  
// ⏩ Example: input 1234 → output: 1 2 3 4 (each digit on a new line).


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
       int Remainder = 0 , reversedNum  = 0;
      while(Number > 0 ){

       Remainder= Number % 10;
       reversedNum = reversedNum * 10 + Remainder;
       Number = Number / 10;

    }

    return reversedNum;
}



void PrintDigits(int Number){

     int Remainder = 0;

     while(Number > 0){
       Remainder= Number % 10;
       cout << Remainder <<endl;
       Number = Number / 10;
     }

}


int main()
{
     PrintDigits(ReverseNumber(ReadPositiveNumber("Enter Number : ")));
     
    return 0;
}
