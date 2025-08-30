#include <iostream>

// 📊 Program to print a formatted multiplication table from 1 to 10  
// 🖨️ Displays header, separators, and all results in a tabular form  


using namespace std;


void PrintHeader(){
  cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n\n";

   for(int i = 1 ; i<= 10 ; i++){
     cout << "\t" << i ;
   }

   cout << "\n------------------------------------------------------------------------------------\n";
}



string columnSeparator(int i){
    if(i < 10){
         return "   |";
    }else{
       return "  |";
    }
}



void PrinMutliplicationTable(){

  PrintHeader();

  for(int i = 1 ; i <= 10 ; i++){

      cout << " "<<i << columnSeparator(i) << "\t";

    for(int j = 1 ; j <= 10 ; j++){
        cout  << i * j << "\t";
    }
    cout <<endl;
  }


}



int main()
{
    PrinMutliplicationTable();
    return 0;
}
