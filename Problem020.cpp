
#include <iostream>

// 🎲 Generates and prints a random character based on the selected type 
// (lowercase, uppercase, special, or digit) ✅  


using namespace std;

enum enCharacterType  {smallLetter = 1 , capitalLetter , specialChar , Digit};


int  RandomNumber(int From , int To){

    int randNumber = rand() % (To - From + 1) + From;
    
    return randNumber;
}


void  PrintRandomCharacter(enCharacterType charType){
    cout << "\n";
    switch(charType){
        case enCharacterType::smallLetter :
            cout << char(RandomNumber(97 , 122));
            break;
        case enCharacterType::capitalLetter :
            cout << char(RandomNumber(65 , 90));
            break;
        case enCharacterType::specialChar :
            cout << char(RandomNumber(33 , 47));
            break;
        case enCharacterType::Digit :
            cout << char(RandomNumber(48 , 57));
            break;
    }
}



int main()
{
    srand((unsigned)time(NULL));

    PrintRandomCharacter(enCharacterType::smallLetter);
    PrintRandomCharacter(enCharacterType::capitalLetter);
    PrintRandomCharacter(enCharacterType::specialChar);
    PrintRandomCharacter(enCharacterType::Digit);

    return 0;
}
