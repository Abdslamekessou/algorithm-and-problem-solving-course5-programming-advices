#include <iostream>

// 🔢 Program to print all prime numbers from 1 up to a user-specified number  
// 🖨️ Checks each number and displays it if it is prime  


using namespace std;

enum enPrimeOrNot  {Prime = 1 , NotPrime = 2 };


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



enPrimeOrNot CheckPrime(int Number){

     for(int i = 2 ; i <= (Number/2) ; i++){
         if(Number % i == 0 ){
            return enPrimeOrNot::NotPrime;
         }
     }

   return enPrimeOrNot::Prime;
}



void PrintPrimeNumbersFrom1ToN(int Number){
    cout << "\n**Prime Numbers From 1 To 10**\n";
    for(int i = 1 ; i <= Number ; i++){

        if(CheckPrime(i) == enPrimeOrNot::Prime){
              cout << "\n" << i <<endl;
        }
     }

}



int main()
{
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please Enter A Number"));

    return 0;
}
