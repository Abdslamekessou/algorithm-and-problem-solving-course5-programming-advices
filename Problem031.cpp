
#include <iostream>
#include <string>
#include <math.h>

// 🎲 This program fills an array with numbers from 1 to N and randomly shuffles their order.
// 🔄 Example: {1, 2, 3, 4, 5} ➡️ {3, 1, 5, 2, 4}

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


void Swap(int& A, int& B)
{
    int Temp;    
    Temp = A;    
    A = B;       
    B = Temp;    
}

void FillArrayWith1ToN(int arr[100] , int arrSize){

        for(int i = 0 ; i < arrSize ; i++){
            arr[i] = i+1;
        }

}


void ShuffleArray(int arr[100] , int arrSize){

        for(int i = 0 ; i < arrSize ; i++){
            
            int index1 = RandomNumber(1 , arrSize) - 1;
            int index2 = RandomNumber(1 , arrSize) - 1;

            Swap( arr[index1], arr[index2]);
        }

}



void  PrintArray(int arr[100] , int arrSize){
    
    for(int i = 0 ; i < arrSize ; i++){
        cout << arr[i] << "  " ;
    }

}



int main(){

    srand((unsigned) time(NULL));

    int arr[100] , arrSize  ;

    arrSize = arrSize = ReadPositiveNumber("Please Enter The Size Of The Array : ");

    FillArrayWith1ToN(arr , arrSize);

    cout << "\nArray Elements Before Shuffle : \n";
    PrintArray(arr , arrSize);

    ShuffleArray(arr , arrSize);

    cout << "\nArray Elements After Shuffle : \n";
    PrintArray(arr , arrSize);

    return 0;
