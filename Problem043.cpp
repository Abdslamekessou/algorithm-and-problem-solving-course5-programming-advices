
#include <iostream>

// ❓ Problem: Fill an array with random numbers, then count how many even numbers it contains.  
// 🎯 Goal: Determine the total number of even numbers in the array.  
// 📌 Example: Array = [10, 15, 20, 33, 40] → Even count = 3 (10, 20, 40)

using namespace std;


int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}



void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    cout << "Enter the length of the array : " << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }

}


int EvenCount(int arr[100], int arrLength) {

    int count = 0;

    for (int i = 0; i < arrLength; i++) {

        if (arr[i] % 2 == 0) {
            count++;
        }

    }

    return count;
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


    int arr[100], arrLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);


    cout << "\nArray  Elements : ";
    PrintArray(arr, arrLength);


    cout << "\nEven numbers count is : " << EvenCount(arr, arrLength) << endl;



    return 0;
}
