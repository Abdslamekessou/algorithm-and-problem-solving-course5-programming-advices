#include <iostream>

// 📝 Problem: Write a program that reads a positive number from the user  
// and checks if it is a perfect number or not, then prints the result.  

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

     for(int Counter = 1 ; Counter < Number ; Counter++){

         if(Number % Counter == 0 ){
            Sum += Counter;
         }
     }

   return Number == Sum;
}



void PrintResults(int Number){

    if(isPerfectNumber(Number)){
        cout <<"\n" <<Number << " is a perfect number" << endl;
    }else{
        cout <<"\n" << Number << " is not a perfect number" << endl;
    }
}


int main()
{
    PrintResults(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
