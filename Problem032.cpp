
#include <iostream> 
#include <math.h> 

// 🎲 Fill an array with random numbers (1-100)  
// 🔄 Copy the array in reverse order and display both  
// Example: Array1: 3 5 7 → Array2: 7 5 3


using namespace std;


int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}




void FillArrayWithRandomElements(int arr[100], int& arrSize) {

    cout << "Please Enter The Size Of The Array : " << endl;
    cin >> arrSize;

    for (int i = 0; i < arrSize; i++) {
        arr[i] = RandomNumber(1, 100);
    }

}


void CopyArrayInReverseOrderd(int arr[100], int arr2[100], int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        arr2[i] = arr[arrSize - 1 - i];
    }

}


void  PrintArray(int arr[100], int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}



int main() {

    srand((unsigned)time(NULL));

    int arr[100], arrSize;

    FillArrayWithRandomElements(arr, arrSize);


    int arr2[100];
    CopyArrayInReverseOrderd(arr, arr2, arrSize);

    cout << "\nArray 1 Elements : \n";
    PrintArray(arr, arrSize);


    cout << "\nArray 2 Elements After Copying Array 1 In Reverse Order : \n";
    PrintArray(arr2, arrSize);


    return 0;
}



