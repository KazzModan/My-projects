#include "DocBuilder.h"

DocBuilder::DocBuilder()
{
	Builder::document = new Doc();
}

void DocBuilder::setHeader() 
{
	Builder::document->setPart(0, "hello");
}

void DocBuilder::setContent() 
{
	Builder::document->setPart(1, "world");

}

void DocBuilder::setEtc() 
{
	Builder::document->setPart(2, "world");

}

HTMLBuilder::HTMLBuilder()
{
	Builder::document->setPart(0, "/h hello /h");
}

void HTMLBuilder::setHeader()
{
	Builder::document->setPart(1, "/b world /b");

}

void HTMLBuilder::setContent()
{
	Builder::document->setPart(2, "/b world /b");

}

void HTMLBuilder::setEtc()
{
}
