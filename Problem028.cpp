
#include <iostream>
#include <string>


// 📋 Write a C++ program that copies elements from one array to another array and displays both arrays 🔄


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

void CopyArray(int arrSource[100] , int arrDestination[100] , int arrSize){

    for(int i = 0 ; i < arrSize ; i++){
        arrSource[i] = arrDestination[i];
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

    int arr2[100] ;
    CopyArray(arr , arr2 , arrSize);

    cout << "\nArray 1 Elements : \n";
    PrintArray(arr , arrSize);

    cout << "\n\nArray 2  Elements After Copy : \n";
    PrintArray(arr2 , arrSize);
    
    return 0;
}
