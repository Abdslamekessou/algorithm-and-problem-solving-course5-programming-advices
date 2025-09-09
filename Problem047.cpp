
#include <iostream>
#include <cmath>


// ❓ Problem: Implement your own rounding function for floating-point numbers
// 🎯 Goal: Round a float to the nearest integer. If fraction >= 0.5 round up, else round down
// 📌 Example: number = 3.7 → 4, number = -2.3 → -2


using namespace std;



float ReadNumber(string message) {

    float Number;

    cout << message << endl;
    cin >> Number;

    return Number;
}



float GetFractionsPart(float number) {
    return number - (int)number;
}



int MyRound(float number) {

    int IntPart = (int) number;

    float FractionPart = GetFractionsPart(number);
    
    if (abs(FractionPart) >= .5) {
        
        if (number > 0) {
           return  ++IntPart;
        }
        else {
           return  --IntPart;
        }
    }
    else {
        return IntPart;
    }

}



int main()
{
    float number = ReadNumber("Please enter a number : ");

    cout << "\nMy round Result : " << MyRound(number) << endl;
    cout << "C++ round function : " << round(number) << endl;

    return 0;
}
