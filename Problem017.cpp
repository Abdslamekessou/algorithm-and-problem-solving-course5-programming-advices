#include <iostream>
#include <string>

// 🔐 Problem: Write a program that simulates a brute-force attack to guess a 3-letter uppercase password (AAA → ZZZ).  
// 📝 The program tries all combinations, counts the attempts, and stops when the correct password is found.  
// 📌 Example: If the password = "AAF", the program will try AAA, AAB, AAC, AAD, AAE, and then AAF → Found after 6 trials.  


using namespace std;


string ReadPassword(){
    string password;

    cout << "Please Enter Password : "<<endl;
    cin >> password;

    return password;
}


bool  GuessPassword(string UserPassword){
    cout << "\n";
    string word = "";
    int counter = 0;

    for(int i = 65; i <= 90 ; i++){

        for(int j = 65 ; j <= 90 ; j++){

            for(int k = 65 ; k <= 90 ; k++){
                
                word += char(i);
                word += char(j);
                word += char(k);
                
                counter++;

                cout << "Trial [" << counter << "] : " << word <<endl;

                if(word == UserPassword){
                    cout << "\n";
                    cout << "Password is : " << UserPassword <<endl;
                    cout << "Found After "  << counter << " Trial(s)" <<endl;

                    return true;
                }

                word = "";
            }
        }

    }

    return false;
}



int main()
{
    
    GuessPassword(ReadPassword());

    return 0;
}
