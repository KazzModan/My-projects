#pragma once
#include "Answer.h"
#include <list>
using std::list;

class Question
{
public:
    Question();
    Question(string textQuestion);

    //show methods
    void printAnswers();
    void print();
    
    //incapsulation
    void setTextQuestion(string textQuestion);
    string getTextQuestion() const;
    
    //check answer
    bool checkAnswer(int indexAnswer);
    //add answer
    void addAnswer(Answer newAnswer);
    ~Question();

private:
    string textQuestion;
    list<Answer> listAnswer;
};
