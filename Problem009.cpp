#include <iostream>

// 🔢 Program to read a positive number and count the frequency of each digit (0–9).
// 🧮 It prints how many times every digit appears inside the given number.

// Example:
// Input  = 1223222
// Output = Digit 1 Frequency is 1 Times(s)
//          Digit 2 Frequency is 5 Times(s)
//          Digit 3 Frequency is 1 Times(s)


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





void PrintAllDigitsFrequency(int Number){

  for(int i = 0 ; i < 10 ; i++){

      short DigitFrequency = 0;

      DigitFrequency = CountDigitFrequency(i , Number);

      if(DigitFrequency != 0 ){
         cout <<"\nDigit " << i << " Frequency is " << DigitFrequency << " Times(s)"<<endl ;
      }
  }

}



int main()
{

     PrintAllDigitsFrequency(ReadPositiveNumber("Please Enter The Main Number?"));

    return 0;
}
