
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



int MyFloor(float number) {

    if (number > 0) {
        return (int)number;
    }
    else {
        return (int)number - 1;
    }

}



int main()
{
    float number = ReadNumber("Please enter a number : ");

    cout << "\nMy floor result : " << MyFloor(number) << endl;
    cout << "C++ floor result : " << floor(number) << endl;

    return 0;
}
