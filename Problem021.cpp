
#include <iostream>

// 🎲 Program generates random keys  
// 📌 Example:  
// Key [1] : QWER-TYUI-OPAS-DFGH  
// Key [2] : JKLM-NOPQ-RSTU-VWXY  

using namespace std;


enum enCharacterType  {smallLetter = 1 , capitalLetter , specialChar , Digit};


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message <<endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}


int  RandomNumber(int From , int To){

    int randNumber = rand() % (To - From + 1) + From;
    
    return randNumber;
}


char  GetRandomCharacter(enCharacterType charType){
    
    switch(charType){
        case enCharacterType::smallLetter :
            return char(RandomNumber(97 , 122));
            break;
        case enCharacterType::capitalLetter :
            return char(RandomNumber(65 , 90));
            break;
        case enCharacterType::specialChar :
            return char(RandomNumber(33 , 47));
            break;
        case enCharacterType::Digit :
            return char(RandomNumber(48 , 57));
            break;
    }

    return '\0';
}


string GenerateWord(enCharacterType CharType , short Length){

    string word = "";

    for(int i = 1 ; i <= Length  ; i++){
        word += GetRandomCharacter(enCharacterType::capitalLetter);
    }

    return word;
}


string generateKey(){

    string key = "";
    
    key = GenerateWord(enCharacterType::capitalLetter , 4 ) + "-";
    key += GenerateWord(enCharacterType::capitalLetter , 4 ) + "-";
    key += GenerateWord(enCharacterType::capitalLetter , 4 ) + "-";
    key += GenerateWord(enCharacterType::capitalLetter , 4 ) ;

    return key;
}


void GenerateKeys(short NumberOfKeys){

    for(int i = 0 ; i < NumberOfKeys ; i++){
        cout << "Key [" << i+1 << "] : " << generateKey() <<endl ;
    }
}



int main()
{
    srand((unsigned)time(NULL));
    
    GenerateKeys(ReadPositiveNumber("Please Enter Number Of Keys That You Want To Generate : "));

    return 0;
}
