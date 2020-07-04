#include "user.h"
bool user::setTitle(string title)
{
	return CheckPeopleName(this->name, title);
}

string user::getTitle() const
{
	return this->name;
}
