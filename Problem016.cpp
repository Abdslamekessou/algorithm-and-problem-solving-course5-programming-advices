#include <iostream>
#include <string>

// 📝 Problem: Print all 3-letter words using uppercase English letters (A–Z).
// 👉 The words should start from "AAA" and end with "ZZZ", covering all combinations.
// ✨ Example: AAA, AAB, AAC, ..., ZZY, ZZZ

using namespace std;


void PrintWordsFromAAAtoZZZ(){

    cout << "\n";
    string word = "";
    
    for(int i = 65; i <= 90 ; i++){

        for(int j = 65 ; j <= 90 ; j++){

            for(int k = 65 ; k <= 90 ; k++){
                
                word += char(i);
                word += char(j);
                word += char(k);
                
                cout << word <<endl;
                word = "";
            }
        }

    }

}



int main()
{
    PrintWordsFromAAAtoZZZ();

    return 0;
}
