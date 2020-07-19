#pragma once
#include <queue>
#include <iostream>
#include "Document.h"
using namespace std;
class Spooler
{
public:
	Spooler();
	void addDoc(Document& doc);
	Document giveDoc();
	size_t getSize();
private:
	priority_queue<Document> myPrQueue;
};

