
#include <iostream>

// 🎲 Generates and prints a random character based on the selected type 
// (lowercase, uppercase, special, or digit) ✅  


using namespace std;

enum enCharacterType  {smallLetter = 1 , capitalLetter , specialChar , Digit};


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



int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharacterType::smallLetter) <<endl;
    cout << GetRandomCharacter(enCharacterType::capitalLetter)<<endl;
    cout << GetRandomCharacter(enCharacterType::specialChar) <<endl;
    cout << GetRandomCharacter(enCharacterType::Digit) <<endl;

    return 0;
}
