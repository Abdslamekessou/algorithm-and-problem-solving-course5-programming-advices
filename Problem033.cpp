
#include <iostream>

 
// 🔑 Problem: Generate random license-like keys and store them in an array  
// 🖨️ Then print all generated keys with their array positions  


using namespace std;


enum enCharacterType { smallLetter = 1, capitalLetter, specialChar, Digit };


int ReadPositiveNumber(string Message) {

    int Number;

    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}



int  RandomNumber(int From, int To) {

    int randNumber = rand() % (To - From + 1) + From;

    return randNumber;
}



char  GetRandomCharacter(enCharacterType charType) {

    switch (charType) {
    case enCharacterType::smallLetter:
        return char(RandomNumber(97, 122));
        break;
    case enCharacterType::capitalLetter:
        return char(RandomNumber(65, 90));
        break;
    case enCharacterType::specialChar:
        return char(RandomNumber(33, 47));
        break;
    case enCharacterType::Digit:
        return char(RandomNumber(48, 57));
        break;
    }

    return '\0';
}



string GenerateWord(enCharacterType CharType, short Length) {

    string word = "";

    for (int i = 1; i <= Length; i++) {
        word += GetRandomCharacter(enCharacterType::capitalLetter);
    }

    return word;
}


string generateKey() {

    string key = "";

    key = GenerateWord(enCharacterType::capitalLetter, 4) + "-";
    key += GenerateWord(enCharacterType::capitalLetter, 4) + "-";
    key += GenerateWord(enCharacterType::capitalLetter, 4) + "-";
    key += GenerateWord(enCharacterType::capitalLetter, 4);

    return key;
}


void FillArraysWithKeys(string arr[100] ,int arrLength) {


    for (int i = 0; i < arrLength; i++) {
		arr[i] = generateKey();
    }
}


void  PrintStringArray(string arr[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        cout <<"Array [" << i+1 <<"] : " << arr[i] << "  " <<endl;
    }
    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    string arr[100]; 
    int  arrLength = 0;

	arrLength = ReadPositiveNumber("Please enter the number of keys to generate: ");

	FillArraysWithKeys(arr, arrLength);

	PrintStringArray(arr, arrLength);

    
    return 0;
}
