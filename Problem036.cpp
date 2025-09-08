
#include <iostream>


// ✍️ Problem: Let the user enter numbers one by one and store them in an array  
// ➕ After each input, ask if they want to add another number (Yes/No)  
// 🖨️ Finally, print the total length of the array and all its elements  
//
// 📝 Example:  
// Input → 10, Yes → 20, Yes → 30, No  
// Output → Array Length = 3, Elements = [10, 20, 30]



using namespace std;



int ReadNumber() {

    int Number;

    cout << "\nPlease enter a number? " << endl;
    cin >> Number;

    return Number;
}


void AddArrayElement(int arr[100] , int &arrLength , int number ){

    arrLength++;
    arr[arrLength - 1] = number;

}




void  InputUserNumbersInArray(int arr[100] , int &arrLength) {

    bool addMore = true;

    do {
        
        AddArrayElement(arr, arrLength, ReadNumber());
        
        cout << "\nDo you want to add more numbers [0] : No , [1] : Yes ?  ";
        cin >> addMore;


    } while (addMore);
    
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

    int arr[100] , arrLength = 0;


    InputUserNumbersInArray(arr , arrLength);

    cout << "\nArray Length : " << arrLength << endl;

    cout << "\nArray  Elements : ";
    PrintArray(arr, arrLength);

    return 0;
}

