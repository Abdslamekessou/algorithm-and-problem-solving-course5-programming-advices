
#include <iostream>
#include <cmath>

// ❓ Problem: Calculate the square root of a number without directly using sqrt()  
// 🎯 Goal: Implement your own square root function using pow()  
// 📌 Example: number = 25 → 5, number = 10 → 3.162...

using namespace std;


float ReadNumber(string message) {

    float Number;

    cout << message << endl;
    cin >> Number;

    return Number;
}


float MySqrt(int number) {

    return pow(number , 0.5);

}



int main()
{
    float number = ReadNumber("Please enter a number : ");

    cout << "\nMy sqrt result : " << MySqrt(number) << endl;
    cout << "C++ sqrt result : " << sqrt(number) << endl;

    return 0;
}
