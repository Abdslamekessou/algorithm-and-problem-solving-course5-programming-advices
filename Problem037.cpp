
#include <iostream>

// 📋 Problem: Fill an array with random numbers, then copy it into another array  
// 🧩 The copy process is done using the function AddArrayElement()  
// 🖨️ Finally, print both arrays to verify they are identical  
//
// 📝 Example:  
// Input → Length = 5  
// Array 1 = [12, 45, 78, 34, 90]  
// Array 2 = [12, 45, 78, 34, 90]


using namespace std;


int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}


int ReadNumber(string message) {

    int Number;

    cout << message << endl;
    cin >> Number;

    return Number;
}



void FillArrayWithRandomNumbers(int arr[100], int arrLength) {


    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}



void AddArrayElement(int arr[100], int& arrLength, int number) {

    arrLength++;
    arr[arrLength - 1] = number;

}


void CopyArrayUsingAddArrayElement(int arrSource[100] , int arrDestination[100], int arrSrcLength , int &arrDesLength) {

    for (int i = 0; i < arrSrcLength; i++) {

        AddArrayElement(arrDestination, arrDesLength, arrSource[i]);

    }

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

    int arr1[100], arr2[100], arr1Length = 0 , arr2Length = 0;

    arr1Length = ReadNumber("\nPlease Enter Length Of Array 1 : ");
    FillArrayWithRandomNumbers(arr1,arr1Length);

    CopyArrayUsingAddArrayElement(arr1, arr2, arr1Length, arr2Length);


    cout << "\nArray 1 Elements : ";
    PrintArray(arr1, arr1Length);

    cout << "\nArray 2 Elements : ";
    PrintArray(arr2, arr2Length);


    return 0;
}

