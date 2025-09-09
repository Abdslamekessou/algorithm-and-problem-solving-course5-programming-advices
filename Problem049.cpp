
#include <iostream>
#include <cmath>

// ❓ Problem: Implement your own ceil function for floating-point numbers
// 🎯 Goal: Return the smallest integer greater than or equal to a given number
// 📌 Example: number = 3.2 → 4, number = -2.7 → -2

using namespace std;


float ReadNumber(string message) {

    float Number;

    cout << message << endl;
    cin >> Number;

    return Number;
}


float GetFractionPart(float Number)
{
    return Number - int(Number);
}


int MyCeil(float number) {

    if (abs(GetFractionPart(number)) > 0) {

        if (number > 0) {
            return  (int)number + 1;
        }
        else {
            return (int)number;
        }

    }
    else {
        return (int)number;
    }
   
}



int main()
{
    float number = ReadNumber("Please enter a number : ");

    cout << "\nMy ceil result : " << MyCeil(number) << endl;
    cout << "C++ ceil result : " << ceil(number) << endl;

    return 0;
}
