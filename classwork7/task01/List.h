#pragma once
template <typename T>
class List
{
public:
	List();
	~List();
	List(T* var, size_t size);
	List(const List& list, size_t size);
	void SetVar(T* var);
	T getVar() const;
	void setEmpty(bool isEmpty);
	bool getEmpty() const;
	size_t getSize(size_t size);
	void setSize(size_t size);
	void addBack(T nVar);
	void Delete(size_t index);
	void addFront(T nVar);
	void print();
	void operator = (const List& data);
	const T& operator [] (size_t index) const;
	void List<T>:: operator += (const List& data);
	void List<T>::operator += (const T& data);
	void find(size_t index);
	friend ostream& operator << (ostream& out, const List& list);
	void sort(size_t leftIndex, size_t rightIndex);
	
private:
	T* var;
	bool isEmpty;
	size_t size;
};

