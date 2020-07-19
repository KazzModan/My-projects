#include "Spooler.h"

Spooler::Spooler()
{
}

void Spooler::addDoc(Document& doc)
{
	if (doc.getLvlv() != 0)
	{
		this->myPrQueue.push(doc);
	}
}

Document Spooler::giveDoc()
{
	Document doc = this->myPrQueue.top();
	this->myPrQueue.pop();
	return doc;
}
size_t Spooler::getSize()
{
	return this->myPrQueue.size();
}