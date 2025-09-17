#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <string> 

// 🧮 Math Quiz Game in C++
// 🎯 Choose number of questions, difficulty, and operation type
// 🔢 Random math problems (➕ ➖ ✖️ ➗) are generated
// ✅ Correct = green screen | ❌ Wrong = red screen + beep
// 🏆 Final results shown, and option to replay


using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel, HardLevel, Mix };

enum enOperationType { Add = 1, Sub, Mult, Div, MixOp };


short ReadHowManyQuestions() {
    short NumberOfQuestions;

    do {

        cout << "How many questions do you want to answer ? " << endl;
        cin >> NumberOfQuestions;

    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

    return NumberOfQuestions;
}


enQuestionLevel ReadQuestionLevel() {

    short QuetionLevel = 0;

    do {

        cout << "Enter Question Level [1] Easy , [2] Med , [3] Hard , [4] Mix ? " << endl;
        cin >> QuetionLevel;

    } while (QuetionLevel < 1 || QuetionLevel > 4);

    return (enQuestionLevel)QuetionLevel;
}


enOperationType ReadOperationType() {

    short OpType = 0;

    do {

        cout << "Enter Question Level [1] Add , [2] Sub , [3] Multiplication , [4] division , [5] Mix ? " << endl;
        cin >> OpType;

    } while (OpType < 1 || OpType > 5);

    return (enOperationType)OpType;
}


int ReadQuestionAnswer() {

    int Answer = 0;

    cin >> Answer;

    return Answer;
}


int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}


string GetOpTypeSymbol(enOperationType OpType) {

    switch (OpType) {
    case enOperationType::Add: return "+";
    case enOperationType::Sub: return "-";
    case enOperationType::Mult: return "*";
    case enOperationType::Div: return "/";
    default: return "Mix";
    }

}


enOperationType GetRandomOperationType() {

    return (enOperationType)RandomNumber(1, 4);
}


string GetQuestionLevelText(enQuestionLevel QuestionLevel) {

    string arrQuestionLevelText[4] = { "Easy" , "Medium" , "Hard" , "Mixed" };
    return arrQuestionLevelText[QuestionLevel - 1];

}


string GetFinalResultsText(bool Pass) {

    if (Pass) return "Pass :-)";
    else return "Fail :-(";

}


void ResetScreen() {
    system("cls");
    system("color 0F"); //Black background 
}


void SetScreenColor(bool Right) {

    if (Right) {
        system("color 2F"); //Green for right answers 
    }
    else {
        system("color 4F"); //Red for incorrect answers 
        cout << "\a"; // Plays an alert sound 
    }
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {

    switch (OpType) {
    case enOperationType::Add: return Number1 + Number2;
    case enOperationType::Sub: return Number1 - Number2;
    case enOperationType::Mult: return Number1 * Number2;
    case enOperationType::Div: return (Number2 != 0) ? (Number1 / Number2) : 0;
    default: return Number1 + Number2;

    }
}


//Store information for a single question 
struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};


//Store information of entire quiz session 
struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongQuestions = 0;
    short NumberOfRightQuestions = 0;
    bool isPass = 0;
};


//Generate random math question based on difficulty and operation type 
stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType) {

    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::Mix)
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);

    if (OperationType == enOperationType::MixOp)
        OperationType = GetRandomOperationType();

    Question.OperationType = OperationType;

    switch (QuestionLevel) {

    case enQuestionLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;

    case enQuestionLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;

    case enQuestionLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;

    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

    Question.QuestionLevel = QuestionLevel;

    return Question;
}


void GenerateQuizQuestions(stQuizz& Quizz) {

    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

        Quizz.QuestionList[QuestionNumber] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);

    }
}



void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber) {

    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";

    cout << Quizz.QuestionList[QuestionNumber].Number1 << "\n";

    cout << "   " << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType) << endl;

    cout << Quizz.QuestionList[QuestionNumber].Number2 << "\n";

    cout << "_____________" << endl;
}



void PrintQuizzResults(stQuizz& Quizz) {

    cout << "\n\n________________________________\n";
    cout << "\n Final Result is " << GetFinalResultsText(Quizz.isPass) << "\n";
    cout << "\n________________________________\n\n";

    cout << "Number Of Questions : " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level     : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "OpType              : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number Of Right Answers : " << Quizz.NumberOfRightQuestions << endl;
    cout << "Number Of Wrong Answers : " << Quizz.NumberOfWrongQuestions << endl;

    SetScreenColor(Quizz.isPass);
}


void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {

    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer == Quizz.QuestionList[QuestionNumber].CorrectAnswer) {

        cout << "\nCorrect\n" << endl;

        Quizz.QuestionList[QuestionNumber].AnswerResult = true;

        Quizz.NumberOfRightQuestions++;
    }
    else {

        cout << "\nWrong ! Correct Answer : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;

        Quizz.QuestionList[QuestionNumber].AnswerResult = false;

        Quizz.NumberOfWrongQuestions++;
    }

    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);

}



void AskAndCorrectQuestionsListAnswers(stQuizz& Quizz) {

    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

        PrintTheQuestion(Quizz, QuestionNumber);

        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(Quizz, QuestionNumber);

    }

    Quizz.isPass = (Quizz.NumberOfRightQuestions >= Quizz.NumberOfWrongQuestions);
}



void PlayMathGame() {

    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionLevel();
    Quizz.OpType = ReadOperationType();

    GenerateQuizQuestions(Quizz);

    AskAndCorrectQuestionsListAnswers(Quizz);

    PrintQuizzResults(Quizz);
}


void StartGame() {

    char PlayAgain = 'Y';

    do {
        ResetScreen();
        PlayMathGame();

        cout << "\n\nDo you want to play again Y/N ? " << endl;
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main() {

    srand((unsigned)time(NULL));

    StartGame();

}
