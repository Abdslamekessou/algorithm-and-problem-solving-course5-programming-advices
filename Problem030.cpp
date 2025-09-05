
#include <iostream>
#include <math.h>

// 🎲 This program generates two arrays filled with random numbers between 1 and 100.
// ➕ It calculates the sum of corresponding elements and prints the result. Example: {10, 20} + {5, 15} ➡️ {15, 35}


using namespace std;


int  RandomNumber(int From , int To){

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


void FillArrayWithRandomElements(int arr[100] , int& arrSize){

        for(int i = 0 ; i < arrSize ; i++){
            arr[i] = RandomNumber(1,100);
        }

}



void SumOf2Arrays(int arr[100] , int arr2[100] , int arrSum[100] , int arrSize){

    for(int i = 0 ; i < arrSize ; i++){
        arrSum[i] = arr[i] + arr2[i];
    }

}



void  PrintArray(int arr[100] , int arrSize){
    
    for(int i = 0 ; i < arrSize ; i++){
        cout << arr[i] << "  " ;
    }

}


int main(){

    srand((unsigned) time(NULL));

    int arr[100] ,  arr2[100] ,  arrSum[100] ,arrSize  ;
    
    arrSize = ReadPositiveNumber("Please Enter The Size Of The Array");

    FillArrayWithRandomElements(arr , arrSize);
    FillArrayWithRandomElements(arr2 , arrSize);
    
    

    cout << "\nArray 1 Elements : \n";
    PrintArray(arr , arrSize);

    cout << "\nArray 1 Elements : \n";
    PrintArray(arr2 , arrSize);


    cout << "\nSum Of Array 1 And Array 2 : \n";
    SumOf2Arrays(arr , arr2 , arrSum , arrSize);
    PrintArray(arrSum , arrSize); 

    return 0;
}
