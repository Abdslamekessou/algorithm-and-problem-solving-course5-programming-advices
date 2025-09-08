
#include <iostream>


// ❓ Problem: Copy only distinct numbers from one array into another array.  
// 🎯 Goal: Remove duplicates so the second array contains unique values only.  
// 📌 Example: Array1 = [10, 10, 10, 50, 50, 70, 70, 70, 70, 90]  
//             Array2 = [10, 50, 70, 90]  



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

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;  

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

short FindNumberPositionInArray(int arr[100], int arrLength, int number)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            return i;  
    }
    
    return -1;
}


bool IsNumberInArray(int arr[100], int arrLength , int number) {

    return FindNumberPositionInArray(arr, arrLength, number) != -1;
}



void AddArrayElement(int arr[100], int& arrLength, int number) {

    arrLength++;
    arr[arrLength - 1] = number;

}



void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int arrSrcLength, int& arrDesLength) {
    
    

    for (int i = 0; i < arrSrcLength; i++) {

        if (!IsNumberInArray(arrDestination, arrDesLength, arrSource[i])) {

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



    int arr1[100] , arr2[100], arr1Length = 0, arr2Length = 0;

    FillArray(arr1, arr1Length);

    CopyDistinctNumbersToArray(arr1, arr2, arr1Length, arr2Length);


    cout << "\nArray 1 Elements : ";
    PrintArray(arr1, arr1Length);


    cout << "\nArray 2 Distinct Numbers : ";
    PrintArray(arr2, arr2Length);



    return 0;
}

