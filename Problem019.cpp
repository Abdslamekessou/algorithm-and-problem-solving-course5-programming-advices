
#include <iostream>
#include <cstdlib>

// 🎲 Generates a random number between From and To 

using namespace std;


int  RandomNumber(int From , int To){

    int randNumber = rand() % (To - From + 1) + From;
    
    return randNumber;
}



int main()
{
    srand((unsigned)time(NULL));

    cout<< RandomNumber(1,10) <<endl;
    cout<< RandomNumber(1,10) <<endl;
    cout<< RandomNumber(1,10) <<endl;

    return 0;
}
