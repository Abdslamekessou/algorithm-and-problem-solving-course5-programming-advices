
#include <iostream>

// ❓ Problem: Fill an array with random numbers, then copy only the prime numbers into another array.  
// 📌 Example: Array1 = [10, 7, 15, 3] → Array2 (Primes) = [7, 3]  


using namespace std;


enum enPrimNotPrime { Prime = 1, NotPrime = 2 };



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



enPrimNotPrime CheckPrime(int Number)
{

    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime; 
    }

    return enPrimNotPrime::Prime;
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



void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrSrcLength, int& arrDesLength) {

    for (int i = 0; i < arrSrcLength; i++) {

        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime) {

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

    CopyPrimeNumbers(arr1, arr2, arr1Length, arr2Length);


    cout << "\nArray 1 Elements : ";
    PrintArray(arr1, arr1Length);


    cout << "\nArray 2 Prime Numbers : ";
    PrintArray(arr2, arr2Length);



    return 0;
}

