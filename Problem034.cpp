
#include <iostream>

// 🔍 Problem: Fill an array with random numbers, then search for a user-given number  
// 📌 Example: Array = [10, 25, 40] → Search 25 → Found at position 1 (order 2)


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

	cout << "Please enter the length of the array: " <<endl;
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


void  PrintArray(int arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    int arr[100] , arrLength;



    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 Elements :\n";
    PrintArray(arr, arrLength);

    int numberToFind = ReadNumber();
    cout << "You are looking for number : " << numberToFind << endl;

    short NumberPosition= FindNumberPositionInArray(arr, arrLength, numberToFind);

    if (NumberPosition == -1) {
        cout << "The number is not found :-(\n";
    }
    else {
        cout << "The number found at position: " << NumberPosition << endl;
        cout << "The number found its order  : " << NumberPosition + 1 << endl;
    }



    return 0;
}


