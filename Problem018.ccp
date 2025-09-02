
#include <iostream>
#include <string>


/*
🔐 Problem: Write a program that encrypts and decrypts a text.
👉 Example:
    Input: "ABC", key = 2
    Encrypted: "CDE"
    Decrypted: "ABC"
*/

using namespace std;


string ReadText(){
    string text;

    cout << "Please Enter A Text : "<<endl;
    getline(cin , text);

    return text;
}



string EncryptText(string text , short encryptionKey){
    
    for(int i = 0 ; i < text.length() ; i++){
        text[i] = char((int) text[i] + encryptionKey);
    }

    return text;

}


string DecryptText(string text , short encryptionKey){
    
    for(int i = 0 ; i < text.length() ; i++){
        text[i] = char((int) text[i] - encryptionKey);
    }

    return text;

}



int main()
{
    const short encryptionKey = 2;
    string text = ReadText();

    string TextAfterEncryption = EncryptText(text , encryptionKey);
    string TextAfterDycryption = DecryptText(TextAfterEncryption , encryptionKey);

    cout << "Name Before Encyrption " << text <<endl;
    cout << "Name After Encyrption " << TextAfterEncryption <<endl;
    cout << "Name After Dycryption " << TextAfterDycryption <<endl;

    return 0;
}
