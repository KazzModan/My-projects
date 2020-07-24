#include "question.h"

Question::Question()
{
    textQuestion = "";
}

Question::Question(string textQuestion)
{
    this->textQuestion = textQuestion;
}

void Question::printAnswers()
{
    for (Answer item : listAnswer)
    {
        item.print();
    }
}

void Question::setTextQuestion(string textQuestion)
{
    this->textQuestion = textQuestion;
}

string Question::getTextQuestion() const
{
    return this->textQuestion;
}

bool Question::checkAnswer(int indexAnswer)
{
    int index = 1;
    for (Answer item : listAnswer)
    {
        if (index == indexAnswer)
        {
            return item.getCorrect();
        }
        index++;
    }
}

void Question::print()
{
    cout << textQuestion << endl;
    printAnswers();
}
void Question::addAnswer(Answer newAnswer)
{
    listAnswer.push_back(newAnswer);
}


Question::~Question()
{
}