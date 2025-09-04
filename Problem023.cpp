
#include <iostream>
#include <string>


// 🎲 Write a C++ program that generates random numbers (1-100), 
//fills an array with user-specified size, and prints the elements 🖨️

using namespace std;


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



void  PrintArray(int arr[100] , int arrSize){
    
    for(int i = 0 ; i < arrSize ; i++){
        cout << arr[i] << "  " ;
    }

}




int main(){

    srand((unsigned) time(NULL));

    int arr[100] , arrSize  ;

    FillArrayWithRandomElements(arr , arrSize);

    cout << "\nArray Elements : ";
    PrintArray(arr , arrSize);
    
    return 0;
}
