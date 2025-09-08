
#include <iostream>

// 🔢 Problem: Fill an array with random numbers between 1 and 100  
// 🧩 Copy only the odd numbers from Array 1 into Array 2 using AddArrayElement()  
// 🖨️ Finally, print both arrays: Array 1 (all numbers) and Array 2 (only odd numbers)  
//
// 📝 Example:  
// Input → Length = 6  
// Array 1 = [12, 45, 78, 33, 90, 17]  
// Array 2 = [45, 33, 17]


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


void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrSrcLength, int& arrDesLength) {

    for (int i = 0; i < arrSrcLength; i++) {

        if (arrSource[i] % 2 != 0) {
            AddArrayElement(arrDestination, arrDesLength, arrSource[i]);
        }
        
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

    int arr1[100], arr2[100], arr1Length = 0, arr2Length = 0;

    arr1Length = ReadNumber("\nPlease Enter Length Of Array 1 : ");
    FillArrayWithRandomNumbers(arr1, arr1Length);

    CopyOddNumbers(arr1, arr2, arr1Length, arr2Length);


    cout << "\nArray 1 Elements : ";
    PrintArray(arr1, arr1Length);

    cout << "\nArray 2 Odd Numbers : ";
    PrintArray(arr2, arr2Length);

    return 0;
}

