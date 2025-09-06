
#include <iostream>

// 🔍 Problem: Fill an array with random numbers, then ask the user for a number to search  
// ✅ If the number exists in the array → display "Yes, the number is found :-)"  
// 🚫 If it does not exist → display "No, the number is not found :-("  
//
// 📝 Example 1: Array = [10, 25, 40], Search = 25 → Output: Yes, the number is found :-)  
// 📝 Example 2: Array = [10, 25, 40], Search = 99 → Output: No, the number is not found :-(


using namespace std;


int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}


int ReadNumber() {

    int Number;

    cout << "Please enter a number to search for?" << endl;
    cin >> Number;

    return Number;
}




void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {

    cout << "\nPlease enter the length of the array: " << endl;
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

short FindNumberPositionInArray(int arr[100], int arrLength, int numberToFind) {

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] == numberToFind) {
            return i;
        }
    }

    return -1;

}

bool isFoundNumberInArray(int arr[100], int arrLength, int numberToFind) {

    return FindNumberPositionInArray(arr, arrLength, numberToFind) != -1;

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

    int arr[100], arrLength;



    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, arrLength);

    int numberToFind = ReadNumber();
    cout << "\nYou are looking for number : " << numberToFind << endl;



    if (!isFoundNumberInArray(arr, arrLength, numberToFind)) {
        cout << "\nNo , The number is not found :-(\n";
    }
    else {
        cout << "\nYes , The number is found :-)\n";
    }



    return 0;
}
