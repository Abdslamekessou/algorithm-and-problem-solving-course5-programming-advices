
#include <iostream>
#include <string>

// 🔍 Write a C++ program that finds the minimum number in a randomly 
//  generated array (1-100) and displays it 📉

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



int MinNumberInArray(int arr[100] , int arrSize){
    int MinNum = arr[0];

    for(int i = 1 ; i < arrSize ; i++){

        if(arr[i] < MinNum){
            MinNum = arr[i];
        }
        
    }
    
    return MinNum;
}




int main(){

    srand((unsigned) time(NULL));

    int arr[100] , arrSize  ;

    FillArrayWithRandomElements(arr , arrSize);

    cout << "\nArray Elements : ";
    PrintArray(arr , arrSize);

    cout << "\n\nMin Number In The Array is : " << MinNumberInArray(arr ,arrSize);
    
    return 0;
}
