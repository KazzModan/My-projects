#include <iostream>
#include <stack>
#include <queue>
#include "Document.h"
#include "Printer.h"
#include "Spooler.h"
using namespace std;

int main()
{
	Document doc(1024, "anime", 3);
	Document doc2(1024, "hentai", 2);

	Spooler spooler;
	spooler.addDoc(doc);
	spooler.addDoc(doc2);

	Printer printer(spooler);

	printer.WorkWithDoc();
	return 0;
}
