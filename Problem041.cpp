#include <iostream>


// ❓ Problem: Check if an array reads the same forwards and backwards (palindrome).  
// 🎯 Goal: Determine whether all elements are symmetric from start to end.  
// 📌 Example: Array = [10, 20, 30, 30, 20, 10] → Palindrome = Yes  
// 📌 Example: Array = [10, 20, 30, 40, 20, 10] → Palindrome = No  



using namespace std;



void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}


bool IsPalindromeArray(int arr[100], int arrLength){

    for (int i = 0; i < arrLength; i++) {

        if (arr[i] != arr[arrLength - i - 1]) {
            return false;
        }

    }

    return true;
}





void  PrintArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));


    int arr[100] , arrLength = 0 ;

    FillArray(arr, arrLength);



    cout << "\nArray  Elements : ";
    PrintArray(arr, arrLength);


    if (IsPalindromeArray(arr, arrLength)) {
        cout << "\nYes , your array is palindrome\n";
    }
    else {
        cout << "\nNo , your array is not palindrome\n";
    }


    return 0;
}
