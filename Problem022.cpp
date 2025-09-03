
#include <iostream>
#include <string>

// 📥 Reads an array of integers from user input.
// 🖨️ Prints the array and checks how often a number appears.
// 🔢 Ensures the number to check is positive.
// 🧮 Uses functions for input, output, and counting.
// 🧪 Example: Input [3, 7, 3, 9, 3], check 3 → Output: repeated 3 times.

using namespace std;


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



void ReadArray(int arr[100] , int& arrSize){
    
    cout << "Please Enter Array Size : " <<endl;
    cin >> arrSize;

    cout << "\nEnter Array Elements:" <<endl;

    for(int i = 0 ; i < arrSize ; i++){
        cout << "Element["<< i+1 << "] : " ;
        cout <<endl;
        cin>> arr[i];
    }

    cout <<endl;

}




void  PrintArray(int arr[100] , int arrSize){
    
    for(int i = 0 ; i < arrSize ; i++){
        cout << arr[i] << "\t" ;
    }

}


int TimesRepeated(int arr[100] , int arrSize ,int Number ){
    int counter = 0 ;

    for(int i = 0 ; i < arrSize ; i++){
        if(arr[i] == Number){
            counter++;
        }
    }

    return counter;
}


int main(){

    int arr[100] , arrSize , NumberToCheck ;
    
    ReadArray(arr,arrSize);
    
    cout << "\nOriginal Array : " <<endl ;
    PrintArray(arr ,arrSize);
    cout << "\n" ;

    NumberToCheck = ReadPositiveNumber("\nPlease Enter The Number You Want To Check : ");
    cout <<"\n"<< NumberToCheck << " Is Repeted " << TimesRepeated(arr , arrSize , NumberToCheck) << " Time(s) " <<endl;

    return 0;
}
