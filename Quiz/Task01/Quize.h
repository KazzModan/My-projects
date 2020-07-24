#include "Question.h"


class Quize
{
public:
	Quize();
	Quize(string title);
	~Quize();
	void EditInfo();
	void setTitle(string title);
	string getTitle()const;
	void Print();
	void addQuestion(Question newQuestion);
	bool checkQuestion(int indeQuestion, int indexAnswer);
	void passQuize();
private:
	string title;
	list<Question> listQuestion;

};