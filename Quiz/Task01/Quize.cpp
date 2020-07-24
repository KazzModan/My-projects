#include <iostream>
#include <List>
#include "Quize.h"
using namespace std;

Quize::Quize()
{
    this->title = "";
}
Quize::Quize(string title)
{
    this->title = title;
}

Quize::~Quize()
{
    this->title ="";
    this->listQuestion.clear();
}

void Quize::EditInfo()
{
    int choose;
    string check;
    size_t counter = 0;
    cout << "Choose: \n";
    cout << "(1) Edit title of this quize. \n";
    cout << "(2) Edit questions of this quize. \n";
    cin >> choose;
    switch (choose)
    {
        case 1:
            cout << "Enter new title of this Quiz: ";
            cin >> check;
            this->setTitle(check);
            break;
        case 2:
            cout << "Enter name of question, that u want to edit: ";
            cin >> check;
            for (Question item : listQuestion)
            {
                if (item.getTextQuestion() == check)
                {
                    cout << "Enter new text: ";
                    cin >> check;
                    item.setTextQuestion(check);
                }
            }
     default:
        break;
    }
}

void Quize::setTitle(string title)
{
    this->title = title;
}

string Quize::getTitle()const
{
    return this->title;
}

void Quize::Print()
{
    cout << "You pass quize: " << this->title << endl;
}

void Quize::addQuestion(Question newQuestion)
{
    this->listQuestion.push_back(newQuestion);
}

bool Quize::checkQuestion(int indeQuestion, int indexAnswer)
{
    int index = 1;
    for (Question item : listQuestion)
    {
        if (index == indeQuestion)
        {
            return item.checkAnswer(indexAnswer);
            break;
        }
        index++;
    }
}

void Quize::passQuize()
{
    int score = 0;
    this->Print();

    int i = 1;
    for (Question item : listQuestion)
    {
        int select_answer = 0;
        item.print();
        cout << "Enter answer the question: ";
        cin >> select_answer;

        bool isCheck = checkQuestion(select_answer, i);
        if (isCheck == true) {
            score++;
        }
        ++i;
    }
    cout << "Score: " << score << "/" << i - 1 << endl;
}
