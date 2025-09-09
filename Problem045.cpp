
#include <iostream>

// ❓ Problem: Fill an array with random numbers (both negative and positive), 
//            then count how many numbers are negative (< 0).  
// 🎯 Goal: Determine the total number of negative numbers in the array.  
// 📌 Example: Array = [-10, 15, 0, -3, 20] → Negative count = 2 (-10, -3)



using namespace std;


int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}



void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    cout << "Enter the length of the array : " << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(-100, 100);
    }

}


int NegativeCount(int arr[100], int arrLength) {

    int count = 0;

    for (int i = 0; i < arrLength; i++) {

        if (arr[i] < 0) {
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


    cout << "\nNegative numbers count is : " << NegativeCount(arr, arrLength) << endl;



    return 0;
}
