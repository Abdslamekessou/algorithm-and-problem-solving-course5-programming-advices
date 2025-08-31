#include <iostream>

// 🚀 Problem: Write a program to count how many times a digit appears inside a number.
// 📝 Example: Number = 122322, Digit = 2 → Frequency = 4


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



int CountDigitFrequency(short DigitToCheck , int Number){

   int Remainder = 0 , FreqCount = 0;

    while(Number > 0 ){

       Remainder = Number % 10;

       if(Remainder == DigitToCheck){
          FreqCount++;
       }

       Number = Number / 10;

    }

    return FreqCount;
}



int main()
{
    int Number = ReadPositiveNumber("Please Enter The Main Number?");
    short DigitToCheck = ReadPositiveNumber("Please Enter Digit To Check?");

    int countDigitFrequency = CountDigitFrequency(DigitToCheck , Number);

    cout <<"\nDigit " << DigitToCheck << " Frequency is " << countDigitFrequency << " Times(s)"<<endl ;

    return 0;
}


