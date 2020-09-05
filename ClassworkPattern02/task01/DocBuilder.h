#pragma once
#include "Builder.h"
class DocBuilder : public Builder
{
public:
	DocBuilder();
	void  setHeader() override;
	void  setContent() override;
	void  setEtc() override;
};
class HTMLBuilder : public Builder
{
public:
	HTMLBuilder();
	void  setHeader() override;
	void  setContent() override;
	void  setEtc() override;
};

