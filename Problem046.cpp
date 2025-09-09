
#include <iostream>
#include <cmath>


// ❓ Problem: Read a floating-point number from the user and display its absolute value.
// 🎯 Goal: Compare a custom absolute value function (MyABS) with C++ built-in abs function.
// 📌 Example: 
//     Input: -5.7
//     Output: My abs Result : 5.7
//             C++ abs function : 5.7


using namespace std;



float ReadNumber(string message) {

    float Number;

    cout << message << endl;
    cin >> Number;

    return Number;
}



float MyABS(float number) {
    
    if (number > 0) {
        return number;
    }
    else
    {
        return number * -1;
    }
}



int main()
{
    float number = ReadNumber("Please enter a number : ");

    cout << "\nMy abs Result : " << MyABS(number) << endl;
    cout << "C++ abs function : " << abs(number) << endl;
    
    return 0;
}
