#include <iostream>

// 🔢 Check if a given positive number is a palindrome or not  
// ↔️ A number is palindrome if it reads the same forwards and backwards  
// 📝 Example: 121 → palindrome ✅ , 123 → not palindrome ❌

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



bool isPalindromeNumber(int Number){

 return Number == ReverseNumber(Number);

}


void PrintIsPalindrome(int Number){

   if(isPalindromeNumber(Number)){
     cout <<"\n" <<Number << " is a palindrome" <<endl;
   }else{
     cout <<"\n" <<Number << " is not a palindrome" <<endl;
   }

}


int main()
{
    PrintIsPalindrome(ReadPositiveNumber("Please Enter A Number : "));

    return 0;
}
