#include "Builder.h"

Builder::Builder()
{
    this->document = new Doc();
}

Doc* Builder::getDoc()
{
    return this->document;
}

Builder::~Builder()
{
    delete this->document;
}
