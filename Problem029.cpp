
#include <iostream>
#include <string>
#include <math.h>

// 🎲 This program generates random numbers and stores them in an array.
// 🔍 Then it filters out prime numbers into a second array. Example: {2, 4, 5} ➡️ {2, 5}


using namespace std;


enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    
    
    for (int Counter = 2; Counter <= M; Counter++)
    {
        
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
    }

    return enPrimNotPrime::Prime;
}



int  RandomNumber(int From , int To){

    int randNumber = rand() % (To - From + 1) + From;
    
    return randNumber;
}


void FillArrayWithRandomElements(int arr[100] , int& arrSize){
        
        cout << "Please Enter Array Size : " << endl;
        cin >> arrSize;

        for(int i = 0 ; i < arrSize ; i++){
            arr[i] = RandomNumber(1,100);
        }

}


void CopyOnlyPrimaryNumbers(int arrSource[100] , int arrDestination[100] , int arrSize , int& arr2Size){

    int j = 0;

    for(int i = 0 ; i < arrSize ; i++){
        
        if(CheckPrime(arrSource[i]) == enPrimNotPrime::Prime){

            arrDestination[j] = arrSource[i];
            j++;
        }
        
    }

    arr2Size = --j;

}




void  PrintArray(int arr[100] , int arrSize){
    
    for(int i = 0 ; i < arrSize ; i++){
        cout << arr[i] << "  " ;
    }

}



int main(){

    srand((unsigned) time(NULL));

    int arr[100] , arrSize  ;

    FillArrayWithRandomElements(arr , arrSize);

    int arr2[100] , arr2Size ;
    CopyOnlyPrimaryNumbers(arr , arr2 , arrSize , arr2Size);

    cout << "\nArray 1 Elements : \n";
    PrintArray(arr , arrSize);

    cout << "\n\nPrime Numbers in Array 2 : \n";
    PrintArray(arr2 , arr2Size);
    
    return 0;
}
