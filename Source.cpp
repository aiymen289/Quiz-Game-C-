#include <iostream>
#include<fstream>
#include <string>
#include <windows.h>
using namespace std;

const int BLACK = 0;//colour code numbers 
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
const int GRAY = 8;
const int LIGHT_BLUE = 9;
const int LIGHT_GREEN = 10;
const int LIGHT_CYAN = 11;
const int LIGHT_RED = 12;
const int LIGHT_MAGENTA = 13;
const int LIGHT_YELLOW = 14;
const int BRIGHT_WHITE = 15;

int score = 0;
class Person //person base class
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() { return name; }
    int getAge() { return age; }
};

class Player : public Person //player class inherited from person
{
public:
    Player(string n, int a) : Person(n, a) {}
};

class Question //base class question
{
protected:
    string question;

public:
    virtual bool display() = 0;
};
class TrueFalseQuestion : public Question //True/False question inherited
{
protected:
    string answer;
public:
    bool display()
    {

        cout <<"\n\n\n"<< question;
        string user_answer;
        cin >> user_answer;
        bool correct = (user_answer == answer);
        if (correct)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
            cout << "Correct!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
            score++;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
            cout << "Incorrect." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
        }
        return correct;
    }
};
class EasyTrueFalse : public TrueFalseQuestion //true flase question inherited
{
public:
    EasyTrueFalse()
    {
        system("cls");
        
        question = "\n\n\t The capital of Spain is Madrid.";
        answer = "true";
    }
};
class EasyTrueFalse1 : public TrueFalseQuestion //true flase question inherited
{
public:
    EasyTrueFalse1()
    {
        question = "Seeds of cotton get dispersed by water.";
        answer = "false";
    }
};
class EasyTrueFalse2 : public TrueFalseQuestion //trueflase question inherited
{
public:
    EasyTrueFalse2()
    {
        question = "Sharks are mammals.";
        answer = "false";
    }
};

class MCQuestion : public Question //mcq question inherited
{
protected:
    string options[4];
    char answer;
public:
    bool display()
    {
        
        cout << "\n\n\n"<<question << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << options[i] << endl;
        }
        char user_answer;
        cout << "\n\n\tEnter your answer (A, B, C, or D): ";
        cin >> user_answer;
        bool correct = (user_answer == answer);
        if (correct) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
            cout << "Correct!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
            score++;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
            cout << "incorrect." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
        }
        return correct;
    }
};

class FillInBlanksQuestion : public Question //fill in the blank inherited
{
protected:
    string answer;

public:
    bool display()
    {
        string user_answer;
        cout << question << endl;
        cout << "\n\tEnter your answer: ";
        cin >> user_answer;
        cout << answer << endl;

        bool correct = (user_answer == answer);
        if (correct)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
            cout << "Correct!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
            score++;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
            cout << "Incorrect." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color
        }
        return correct;
    }
};
class EasyGrammarMCQ : public MCQuestion {
public:
    EasyGrammarMCQ() 
    {
        system("cls");
        question = " -->Choose the correct form of the verb:\n\n    He ____ to the store.";
        options[0] = "\n\tA. go";
        options[1] = "\n\tB. goes";
        options[2] = "\n\tC. went";
        options[3] = "\n\tD. going";
        answer = 'B';
    }
};
class EasyGrammarMCQ1 : public MCQuestion {
public:
    EasyGrammarMCQ1() {
        question = "\n I ____ what was happening.";
        options[0] = "\n\tA. can't";
        options[1] = "\n\tB. couldn’t understand";
        options[2] = "\n\tC. was not able to understood";
        options[3] = "\n\tD. was not able to stand";
        answer = 'B';
    }
};
class EasyGrammarMCQ2 : public MCQuestion {
public:
    EasyGrammarMCQ2() {
        question = "\nChoose the correct form of the verb:\n The valley___quiet and beautiful in the morning.";
        options[0] = "\n\tA. lay";
        options[1] = "\n\tB. lays";
        options[2] = "\n\tC. laid";
        options[3] = "\n\tD. none of the above";
        answer = 'A';
    }
};

class EasyGrammarFillInBlanks : public FillInBlanksQuestion {
public:
    EasyGrammarFillInBlanks() {
        system("cls");
        question = "\n\nFill in the blank:\n\n The train __ as fast as the bus.";
        answer = "moves";
    }
};
class EasyGrammarFillInBlanks1 : public FillInBlanksQuestion {
public:
    EasyGrammarFillInBlanks1() {
        question = "\n\nFill in the blank:\n\n I __ a terrible experience yesterday..";
        answer = "had";
    }
};
class EasyGrammarFillInBlanks2 : public FillInBlanksQuestion {
public:
    EasyGrammarFillInBlanks2() {
        question = "\n\nFill in the blank:\n\n Each of us __ the world differently.";
        answer = "sees";
    }
};
class MediumTrueFalse : public TrueFalseQuestion //trueflase question inherited
{
public:
    MediumTrueFalse()
    {
        system("cls");
        question = "\n\nAbstraction in object-oriented programming is hiding the implementationand showing only the features.";
        answer = "true";
    }
};
class MediumTrueFalse1 : public TrueFalseQuestion //trueflase question inherited
{
public:
    MediumTrueFalse1()
    {
        question = "\n\nDo Platform independent does come under OOP concept?";
        answer = "false";
    }
};
class MediumTrueFalse2 : public TrueFalseQuestion //trueflase question inherited
{
public:
    MediumTrueFalse2()
    {
        question = "\n\n Inheritence is only public  private and protected.";
        answer = "true";
    }
};
class MediumMathMCQ : public MCQuestion {
public:
    MediumMathMCQ() {
        system("cls");
        question = "\n\n\tWhat is the square root of 64?";
        options[0] = "\n\tA. 4";
        options[1] = "\n\tB. 6";
        options[2] = "\n\tC. 8";
        options[3] = "\n\tD. 10";
        answer = 'C';
    }
};
class MediumMathMCQ1 : public MCQuestion {
public:
    MediumMathMCQ1() {
        question = "\n\nWhat is the answer of (10*2)+3";
        options[0] = "\n\tA. 4";
        options[1] = "\n\tB. 06";
        options[2] = "\n\tC. 23";
        options[3] = "\n\tD. 50";
        answer = 'C';
    }
};
class MediumMathMCQ2 : public MCQuestion {
public:
    MediumMathMCQ2() {
        system("cls");
        question = "\n\nIn 347, the value of 7 is?  ";
        options[0] = "\n\tA. tens";
        options[1] = "\n\tB. hundreds ";
        options[2] = "\n\tC. right most";
        options[3] = "\n\tD. ones";
        answer = 'D';
    }
};

class MediumMathFillInBlanks : public FillInBlanksQuestion {
public:
    MediumMathFillInBlanks() {
        system("cls");
        question = "\n\nFill in the blank:\n\nThe area of a circle is equal to pi times the _ of the circle.";
        answer = "radius";
    }
};
class MediumMathFillInBlanks1 : public FillInBlanksQuestion {
public:
    MediumMathFillInBlanks1() {
        question = "\nFill in the blank:\n\n 3.1417 is the value of _ .";
        answer = "pi";
    }
};
class MediumMathFillInBlanks2 : public FillInBlanksQuestion {
public:
    MediumMathFillInBlanks2() {
        question = "\nWhat is a shape that has no sides and no corners known as?.";
        answer = "triangle";
    }
};

class HardProgramMCQ : public MCQuestion
{
public:
    HardProgramMCQ()
    {
        system("cls");
        question = "Who invented OOP?";
        options[0] = "\n\tA. Andrea Ferro";
        options[1] = "\n\tB. Adele Goldberg";
        options[2] = "\n\tC. Alan Kay";
        options[3] = "\n\tD. Dennis Ritchie";
        answer = 'C';
    }
};
class HardProgramMCQ1 : public MCQuestion
{
public:
    HardProgramMCQ1()
    {
        question = "Which feature of OOP indicates code reusability?";
        options[0] = "\n\tA. Abstraction";
        options[1] = "\n\tB. Inheritance";
        options[2] = "\n\tC. Polymorphism";
        options[3] = "\n\tD. Encapsulation";
        answer = 'B';
    }
};
class HardProgramMCQ2 : public MCQuestion
{
public:
    HardProgramMCQ2()
    {
        question = "\nWhich feature of OOP is indicated by the following code?\n\Nclass student { int marks; };class topper :public student { int age;  topper(int age) { this.age = age; } }; ?";
        options[0] = "\n\tA. Inheritance and polymorphism";
        options[1] = "\n\tB. Inheritance";
        options[2] = "\n\tC. Polymorphism ";
        options[3] = "\n\tD. Encapsulation and Inheritance";
        answer = 'D';
    }
};

class HardProgramFillInBlanks : public FillInBlanksQuestion
{
public:
    HardProgramFillInBlanks()
    {
        system("cls");
        question = "\n\n\tFill in the blank:\n\n\tInheritance allows a class to inherit properties and behaviors from a __ class.";
        answer = "parent class";
    }
};
class HardProgramFillInBlanks1 : public FillInBlanksQuestion
{
public:
    HardProgramFillInBlanks1()
    {
        question = "\n\n\tFill in the blank:\n\n\t A method that has the same name as the class it belongs to is called a __.";
        answer = "constructor";
    }
};
class HardProgramFillInBlanks2 : public FillInBlanksQuestion
{
public: 
    HardProgramFillInBlanks2()
    {
        question = "\nFill in the blank:\n\n\t Abstraction in OOP refers to the process of simplifying complex systems by showing only _ details.";
        answer = "relevant";
    }
};
class HardTrueFalse : public TrueFalseQuestion //trueflase question inherited
{
public:
    HardTrueFalse()
    {
        system("cls");
        question = "\n\tThe past tense of must is musted.";
        answer = "false";
    }
};
class HardTrueFalse1 : public TrueFalseQuestion //trueflase question inherited
{
public:
    HardTrueFalse1()
    {
        question = "\n\tThird form of accept is accepted";
        answer = "true";
    }
};
class HardTrueFalse2 : public TrueFalseQuestion //trueflase question inherited
{
public:
    HardTrueFalse2()
    {
        question = "\n\tOop allows us to reuse the code.";
        answer = "true";
    }
};
int main()
{
   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHT_CYAN);
    cout << "\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHT_MAGENTA);
    cout << "\t\t\t\t                    QUIZ GAME" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHT_CYAN);
    cout << "\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++\n\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << endl;
    cout << endl;

    fstream easy;
    fstream medium;
    fstream hard;
    fstream info;
    
    string playerName;
    int playerAge;
    char playAgain = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "\n\tEnter your name: ";
    cin>>playerName;
    cout << "\n\tEnter your age: ";
    cin >> playerAge;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
    system("cls");
    info.open("player.dat", ios::out);
    {
        info << playerName << endl;
        info << playerAge << endl;
        info.close();
    }
    int choice;
    if (playerAge<= 10) {
        choice = 1;
    }
    else if (playerAge<= 15) {
        
        choice = 2;
    }
    else {
       
       choice = 3;
    }
    cout << "\n\n\n -->Suggested level according to your age " << choice;
    Player player(playerName, playerAge);
    do
    {
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHT_CYAN);
        cout<<"\n\n\t\t\t---------------------------------------------------";
        cout << "\n\t\t\t\t\tchoices"<<endl;
        cout << "\n\t\t\t---------------------------------------------------";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        cout << "\n\n\n\n\   -->Choose the difficulty level:" << endl<<endl;
        cout << "\t\t1. Easy" << endl<<endl;
        cout << "\t\t2. Medium" << endl<<endl;
        cout << "\t\t3. Hard" << endl<<endl;
        cout << "\n\n   -->Enter your choice: ";
        cin >> choice;
        system("cls");
        Question* question1 = nullptr;
        Question* question2 = nullptr; // Initialize question2 to nullptrS
        Question* question3 = nullptr; // Initialize question3 to nullptrS
        bool result;

        if (choice == 1)
        {
            EasyGrammarMCQ easyGrammarMCQ;
            EasyGrammarMCQ1 easyGrammarMCQ1;
            EasyGrammarMCQ2 easyGrammarMCQ2;
            EasyGrammarFillInBlanks easyGrammarFillInBlanks;
            EasyGrammarFillInBlanks1 easyGrammarFillInBlanks1;
            EasyGrammarFillInBlanks2 easyGrammarFillInBlanks2;
            EasyTrueFalse easyTrueFalse;
            EasyTrueFalse1 easyTrueFalse1;
            EasyTrueFalse2 easyTrueFalse2;
            int question_choice;

            easy.open("easy.dat", ios::out);

            cout << "\n\n\n\t  -->Choose the type of question to attempt:" << endl<<endl;
            cout << "\n\t\t1. MCQ" << endl ;
            cout << "\n\t\t2. Fill in the blanks"  << endl;
            cout << "\n\t\t3. True or False" << endl << endl;
            cout << "\n\n\t   -->Enter your choice: ";
            cin >> question_choice;
            system("cls");
            if (question_choice == 1)
            {
                question1 = &easyGrammarMCQ;
                question2 = &easyGrammarMCQ1;
                question3 = &easyGrammarMCQ2;
            }
            else if (question_choice == 2)
            {
                question1 = &easyGrammarFillInBlanks;
                question2 = &easyGrammarFillInBlanks1;
                question3 = &easyGrammarFillInBlanks2;
            }
            else if (question_choice == 3)
            {
                question1 = &easyTrueFalse;
                question2 = &easyTrueFalse1;
                question3 = &easyTrueFalse2;
            }
            else
            {
                cout << "Invalid choice." << endl;
                return 0;
            }
            result = question1->display();
            cin.ignore();
            result = question2->display();
            cin.ignore();
            result = question3->display();
            hard << score << "/3" << endl;
            cout << "\n\t\t-------------------------------------";
            cout << "\n\t\t\tYou have Scored:\t" << score << "/3" << endl;
            cout << "\t\t-------------------------------------";
            easy << score << "/3" << endl;
            easy.close();
        }
        else if (choice == 2)
        {
            MediumMathMCQ mediumMathMCQ;
            MediumMathMCQ1 mediumMathMCQ1;
            MediumMathMCQ2 mediumMathMCQ2;
            MediumMathFillInBlanks mediumMathFillInBlanks;
            MediumMathFillInBlanks1 mediumMathFillInBlanks1;
            MediumMathFillInBlanks2 mediumMathFillInBlanks2;
            MediumTrueFalse  mediumTrueFalse;
            MediumTrueFalse1  mediumTrueFalse1;
            MediumTrueFalse2  mediumTrueFalse2;
            int question_choice;
            system("cls");
            cout << "\n\n\n\t  -->Choose the type of question to attempt:" << endl;
            cout << "\n\t\t1. MCQ" << endl;
            cout << "\n\t\t2. Fill in the blanks" << endl;
            cout << "\n\t\t3. True or false" << endl;
            cout << "\n\n   -->Enter your choice: ";
            cin >> question_choice;
            medium.open("medium.dat", ios::out);
            if (question_choice == 1)
            {
                question1 = &mediumMathMCQ;
                question2 = &mediumMathMCQ1;
                question3 = &mediumMathMCQ2;
            }
            else if (question_choice == 2)
            {
                question1 = &mediumMathFillInBlanks;
                question2 = &mediumMathFillInBlanks1;
                question3 = &mediumMathFillInBlanks2;
            }
            else if (question_choice == 3)
            {
                question1 = &mediumTrueFalse;
                question2 = &mediumTrueFalse1;
                question3 = &mediumTrueFalse2;
            }
            else
            {
                cout << "Invalid choice." << endl;
                return 0;
            }
            system("cls");
            result = question1->display();
            cin.ignore();
            result = question2->display();
            cin.ignore();
            result = question3->display();
            medium << score << "/3" << endl;
            hard << score << "/3" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHT_CYAN);
            cout << "\n\t\t-------------------------------------";
            cout << "\n\t\t\tYou have Scored:\t" << score << "/3" << endl;
            cout << "\t\t-------------------------------------";
            medium.close();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (choice == 3)
        {
            HardProgramMCQ  hardProgramMCQ;
            HardProgramMCQ1 hardProgramMCQ1;
            HardProgramMCQ2 hardProgramMCQ2;
            HardProgramFillInBlanks  hardProgramFillInBlanks;
            HardProgramFillInBlanks1 hardProgramFillInBlanks1;
            HardProgramFillInBlanks2 hardProgramFillInBlanks2;
            HardTrueFalse  hardTrueFalse;
            HardTrueFalse1  hardTrueFalse1;
            HardTrueFalse2 hardTrueFalse2;
            int question_choice;
            system("cls");
            cout << "\n\n\n\n\t -->Choose the type of question to attempt:" << endl;
            cout << "\nt\t1. MCQ" << endl;
            cout << "\n\t2. Fill in the blanks" << endl;
            cout << "\n\t3. True or False" << endl;
            cout << "\n\n\t--> Enter your choice: ";
            cin >> question_choice;
            system("cls");
            hard.open("hard.dat", ios::out);
            if (question_choice == 1)
            {
                question1 = &hardProgramMCQ;
                question2 = &hardProgramMCQ1;
                question3 = &hardProgramMCQ2;
            }
            else if (question_choice == 2)
            {
                question1 = &hardProgramFillInBlanks;
                question2 = &hardProgramFillInBlanks1;
                question3 = &hardProgramFillInBlanks2;
            }
            else if (question_choice == 3)
            {
                question1 = &hardTrueFalse;
                question2 = &hardTrueFalse1;
                question3 = &hardTrueFalse2;
            }
            else
            {
                cout << "Invalid choice." << endl;
                return 0;
            }

            result = question1->display();
            cin.ignore();
            result = question2->display();
            cin.ignore();
            result = question3->display();
            hard << score << "/3" << endl;

           cout << "\n\t\t-------------------------------------";
            cout << "\n\t\t\tYou have Scored:\t" << score << "/3" << endl;
            cout << "\t\t-------------------------------------";
            hard.close();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
        cout << "\n\n\t -->Do you want to play again? (Y/N): ";
        cin >> playAgain;
        system("cls");
        if (playAgain == 'Y' || playAgain == 'y')
        {
            score = 0;
        }
    } while (playAgain == 'Y' || playAgain == 'y');
    return 0;
}