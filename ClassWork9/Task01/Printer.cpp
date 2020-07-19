#include "Printer.h"
#include <Windows.h>
Printer::Printer(Spooler spoler)
{
	this->docs = spoler;
}
void Printer::WorkWithDoc()
{
	Document doc;
	while (this->docs.getSize() != 0)
	{
		if (this->docs.getSize() != 0)
			doc = this->docs.giveDoc();
		
		for (size_t i = 0; i < 100; i++)
		{
			system("cls");
			cout << "name of document: " << doc.getName() << endl;
			cout << " size of this doc: " << doc.getSize() << " Kbit\n";
			cout << "Printing: " << i + 1 << "%\n";
			Sleep(10);
		}
		cout << "Print Completed\n";
	}
}
