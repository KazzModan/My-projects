#pragma once
struct Element
{
	int ownerPoints;
	int oppPoint;
	char name[20];
	char opponent[20];

	Element* right;
	Element* left;

	Element* parents;
};
class tree
{
public:
	tree();
	~tree();
	void print(Element* node);
	Element* search(Element* node, char* key);
	Element* min(Element* node);
	Element* max(Element* node);
	void insert(Element* nElement);
	void DelelteAll(Element* z = 0);
	void Delete(Element* z);
	Element* getRoot();
	Element* Next(Element* node);
	Element* Prev(Element* node);
private: 
	Element* root;
};

