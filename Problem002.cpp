#include <iostream>

// 🔢 Program to print all prime numbers from 1 up to a user-specified number
// 🖨️ Checks each number and displays it if it is prime


using namespace std;

enum enPrimeNotPrime {Prime = 1 , NotPrime = 2 };


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);


    return Number;
}



enPrimeNotPrime CheckPrime(int Number){

     for(int Counter = 2 ; Counter <= (Number/2) ; Counter++){
         
         if(Number % Counter == 0 ){
            return enPrimeNotPrime::NotPrime;
         }
         
     }

   return enPrimeNotPrime::Prime;
}



void PrintPrimeNumbersFrom1ToN(int Number){
    cout << "\n** Prime Numbers From 1 To "<< Number << " **\n";
    
    for(int Counter = 1 ; Counter <= Number ; Counter++){

        if(CheckPrime(Counter) == enPrimeNotPrime::Prime){
              cout << "\n" << Counter <<endl;
        }
        
     }

}



int main()
{
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please Enter A Number?"));

    return 0;
}

