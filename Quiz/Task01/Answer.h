#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Answer
{
private:
    string textAnswer;
    bool correct;

public:
    Answer();
    Answer(string textAnswer, bool correct);
    
    //getters
    bool getCorrect() const;
    string getTextAnswer() const;
    
    //setters
    void setCorrect(bool correct);
    void setTextAnswer(string textAnswer);

    //show answer
    void print();

    ~Answer();
};