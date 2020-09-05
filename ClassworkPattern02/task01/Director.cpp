#include "Director.h"

Director::Director()
{
}

Director::Director(Builder* build)
{
	this->build = build;
}

Doc* Director::Create()
{
	build->setHeader();
	build->setContent();
	build->setEtc();
	return build->getDoc();
}
