#include <iostream>
#include <cstdlib>
#include <ctime>
#include  <string>


// 🎮 Project: Stone 🪨, Paper 📄, Scissors ✂️ Game  
// 👤 The player chooses a move: [1 = Stone, 2 = Paper, 3 = Scissors].  
// 🤖 The computer also selects a move randomly.  
// ⚔️ Each round compares the choices and decides the winner:  
//     🪨 beats ✂️   → Example: Player = Stone, Computer = Scissors → Player wins.  
//     📄 beats 🪨   → Example: Player = Paper, Computer = Stone → Player wins.  
//     ✂️ beats 📄   → Example: Player = Scissors, Computer = Paper → Player wins.  
// 🤝 If both choose the same, the round is a Draw.  
// 🧮 The program counts wins, losses, and draws across all rounds.  
// 🏆 At the end, it shows the final results and declares the overall winner.  

using namespace std;

enum enGameChoice  {Stone = 1 , Paper = 2 , Scissors = 3};

enum enWinner {Player1 = 1 , Computer = 2 , Draw = 3 };


struct stRoundInfo {

    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};


struct stGameResults {

    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";

};


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}


enWinner WhoWonTheRound(stRoundInfo RoundInfo) {

    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice) {

        case enGameChoice::Stone:
            return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Paper:
            return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Scissors:
            return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;

    }

}


void ResetScreen() {
    system("cls");
    system("color 0F");
}


void setWinnerColor(enWinner Winner) {

    switch (Winner) {

        case enWinner::Player1 :
            system("color 2F");
            break;

        case enWinner::Computer :
            system("color 4F");
            cout << "\a";
            break;

        case  enWinner::Draw :
            system("color 6F");
            break;

    }
}


enWinner WhoWonTheGame(short Player1WinTimes , short ComputerWinTimes) {

    if (Player1WinTimes > ComputerWinTimes) {
        return enWinner::Player1;
    }else if (Player1WinTimes < ComputerWinTimes) {
        return enWinner::Computer;
    }else {
        return enWinner::Draw;
    }
}



string ChoiceName(enGameChoice Choice) {

    string arrGameChoices[3] = {"Stone" , "Paper" , "Scissors"};
    return arrGameChoices[Choice - 1];

}



string WinnerName(enWinner Winner) {

    string arrWinnerName[3] = {"Player1" , "Computer" , "(No Winner) Draw"};
    return arrWinnerName[Winner - 1];

}



short ReadHowManyRounds() {
    short rounds;

    do {
        cout << "\nHow Many Rounds (1-10) " << endl;
        cin >> rounds;

    } while (rounds <1 || rounds > 10);

    return rounds;
}



enGameChoice GetComputerChoice() {

    return  (enGameChoice) RandomNumber(1 , 3);

}



enGameChoice ReadPlayer1Choice() {

    short choice;

    do {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? " << endl;
        cin >> choice;

    } while (choice <1 || choice > 3);

    return  (enGameChoice) choice;
}



string Tabs(short NumberOfTabs) {
    string t = "";

    for (int i = 1 ; i < NumberOfTabs ; i++) {
        t += "\t";
    }

    return t;
}



void PrintRoundResults(stRoundInfo RoundInfo) {

    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n" ; // why it always zero
    cout << "Player 1 Choice: " << ChoiceName(RoundInfo.Player1Choice) <<endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) <<endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName <<  "]\n";
    cout << "_________________________________________\n" << endl;

    setWinnerColor(RoundInfo.Winner);

}



void ShowGameOverScreen() {
    cout << "\n";
    cout << Tabs(2)<<"_____________________________________________________________\n\n";
    cout << Tabs(2)<<"                       +++GameOver+++ \n";
    cout << Tabs(2)<<"_____________________________________________________________\n\n";
}


void ShowFinalGameResults(stGameResults GameResults) {
    cout << Tabs(2) <<"_____________________[ Game Results ]________________________\n\n";
    cout << Tabs(2) <<"Game Rounds         :  " << GameResults.GameRounds << endl;
    cout << Tabs(2) <<"Player won times    :  " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) <<"Computer won times  :  " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) <<"Draw times          :  " << GameResults.DrawTimes<< endl;
    cout << Tabs(2) <<"Final Winner        :  " << GameResults.WinnerName << endl;

    setWinnerColor(GameResults.GameWinner);
}



stGameResults PlayGame(short HowManyRounds) {

    stRoundInfo RoundInfo;
    short Player1WinTimes = 0 , ComputerWinTimes = 0 , DrawTimes = 0 ;

    for (short GameRound = 1 ; GameRound <= HowManyRounds ; GameRound++) {

        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1) {
            Player1WinTimes++;
        }else if (RoundInfo.Winner == enWinner::Computer) {
            ComputerWinTimes++;
        }else {
            DrawTimes++;
        }

        PrintRoundResults(RoundInfo);
    }

    return  {
        HowManyRounds ,
        Player1WinTimes ,
        ComputerWinTimes ,
        DrawTimes ,
        WhoWonTheGame(Player1WinTimes , ComputerWinTimes),
        WinnerName(WhoWonTheGame(Player1WinTimes , ComputerWinTimes))
    };
}



void StartGame() {
    char PlayAgain = 'Y';

    do {

        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);


        cout << "\nDo you want to play again? (Y/N): ";
        cin >>ws >>PlayAgain;

    }while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
    srand((unsigned)time(NULL));

    StartGame();
}


