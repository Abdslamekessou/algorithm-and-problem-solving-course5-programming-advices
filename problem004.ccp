#include <iostream>

// 🚀 Problem: Write a program to print all perfect numbers from 1 up to N.
// ✅ A perfect number is a number whose proper divisors sum up exactly to the number itself.


using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



bool isPerfectNumber(int Number){

    int Sum = 0 ;

     for(int Counter = 1 ; Counter <= (Number/2) ; Counter++){

         if(Number % Counter == 0 ){
            Sum += Counter;
         }
     }

   return Number == Sum;
}



void PrintPerfectNumbersFrom1ToN(int Number){

    cout << "\n** Perfect Numbers From 1 To " << Number << " **\n";

    for(int i = 1 ; i <= Number ; i++){

       if(isPerfectNumber(i)){
          cout << "\n" << i <<endl ;
       }

    }

}


int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
